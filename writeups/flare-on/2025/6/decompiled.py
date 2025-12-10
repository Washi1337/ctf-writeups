# Decompiled with PyLingual (https://pylingual.io)
# Internal filename: challenge_to_compile.py
# Bytecode version: 3.12.0rc2 (3531)
# Source timestamp: 1970-01-01 00:00:00 UTC (0)

import tkinter as tk
from tkinter import scrolledtext, messagebox, simpledialog, Checkbutton, BooleanVar, Toplevel
import platform
import hashlib
import time
import json
from threading import Thread
import math
import random
from Crypto.PublicKey import RSA
from Crypto.Util.number import bytes_to_long, long_to_bytes, isPrime
import os
import sys
from web3 import Web3
from eth_account import Account
from eth_account.signers.local import LocalAccount

def resource_path(relative_path):
    """\n    Get the absolute path to a resource, which works for both development\n    and for a PyInstaller-bundled executable.\n    """  # inserted
    try:
        base_path = sys._MEIPASS
    except Exception:
        pass  # postinserted
    else:  # inserted
        return os.path.join(base_path, relative_path)
        base_path = os.path.abspath('.')

class SmartContracts:
    rpc_url = ''
    private_key = ''

    def deploy_contract(contract_bytes, contract_abi):
        try:
            w3 = Web3(Web3.HTTPProvider(SmartContracts.rpc_url))
            if not w3.is_connected():
                raise ConnectionError(f'[!] Failed to connect to Ethereum network at {SmartContracts.rpc_url}')
            print(f'[+] Connected to Sepolia network at {SmartContracts.rpc_url}')
            print(f'[+] Current block number: {w3.eth.block_number}')
            if not SmartContracts.private_key:
                raise ValueError('Please add your private key.')
            account = Account.from_key(SmartContracts.private_key)
            w3.eth.default_account = account.address
            print(f'[+] Using account: {account.address}')
            balance_wei = w3.eth.get_balance(account.address)
            print(f"[+] Account balance: {w3.from_wei(balance_wei, 'ether')} ETH")
            if balance_wei == 0:
                print('[!] Warning: Account has 0 ETH. Deployment will likely fail. Get some testnet ETH from a faucet (e.g., sepoliafaucet.com)!')
            Contract = w3.eth.contract(abi=contract_abi, bytecode=contract_bytes)
            gas_estimate = Contract.constructor().estimate_gas()
            print(f'[+] Estimated gas for deployment: {gas_estimate}')
            gas_price = w3.eth.gas_price
            print(f"[+] Current gas price: {w3.from_wei(gas_price, 'gwei')} Gwei")
            transaction = Contract.constructor().build_transaction({'from': account.address, 'nonce': w3.eth.get_transaction_count(account.address), 'gas': gas_estimate + 200000, 'gasPrice': gas_price})
            signed_txn = w3.eth.account.sign_transaction(transaction, private_key=SmartContracts.private_key)
            print('[+]  Deploying contract...')
            tx_hash = w3.eth.send_raw_transaction(signed_txn.raw_transaction)
            print(f'[+] Deployment transaction sent. Hash: {tx_hash.hex()}')
            print('[+] Waiting for transaction to be mined...')
            tx_receipt = w3.eth.wait_for_transaction_receipt(tx_hash, timeout=300)
            print(f'[+] Transaction receipt: {tx_receipt}')
            if tx_receipt.status == 0:
                print('[!] Transaction failed (status 0). It was reverted.')
                return
            contract_address = tx_receipt.contractAddress
            print(f'[+] Contract deployed at address: {contract_address}')
            deployed_contract = w3.eth.contract(address=contract_address, abi=contract_abi)
            return deployed_contract
        except ConnectionError as e:
            print(f'[!] Connection error: {e}')
            print('Please check your RPC_URL and network connection.')
            return None
        except ValueError as e:
            print(f'[!] Configuration error: {e}')
            return None
        except Exception as e:
            print(f'[!] An unexpected error occurred: {e}')
            return None

class LCGOracle:
    def __init__(self, multiplier, increment, modulus, initial_seed):
        self.multiplier = multiplier
        self.increment = increment
        self.modulus = modulus
        self.state = initial_seed
        self.contract_bytes = '6080604052348015600e575f5ffd5b506102e28061001c5f395ff3fe608060405234801561000f575f5ffd5b5060043610610029575f3560e01c8063115218341461002d575b5f5ffd5b6100476004803603810190610042919061010c565b61005d565b6040516100549190610192565b60405180910390f35b5f5f848061006e5761006d6101ab565b5b86868061007e5761007d6101ab565b5b8987090890505f5f8411610092575f610095565b60015b60ff16905081816100a69190610205565b858260016100b49190610246565b6100be9190610205565b6100c89190610279565b9250505095945050505050565b5f5ffd5b5f819050919050565b6100eb816100d9565b81146100f5575f5ffd5b50565b5f81359050610106816100e2565b92915050565b5f5f5f5f5f60a08688031215610125576101246100d5565b5b5f610132888289016100f8565b9550506020610143888289016100f8565b9450506040610154888289016100f8565b9350506060610165888289016100f8565b9250506080610176888289016100f8565b9150509295509295909350565b61018c816100d9565b82525050565b5f6020820190506101a55f830184610183565b92915050565b7f4e487b71000000000000000000000000000000000000000000000000000000005f52601260045260245ffd5b7f4e487b71000000000000000000000000000000000000000000000000000000005f52601160045260245ffd5b5f61020f826100d9565b915061021a836100d9565b9250828202610228816100d9565b9150828204841483151761023f5761023e6101d8565b5b5092915050565b5f610250826100d9565b915061025b836100d9565b9250828203905081811115610273576102726101d8565b5b92915050565b5f610283826100d9565b915061028e836100d9565b92508282019050808211156102a6576102a56101d8565b5b9291505056fea2646970667358221220c7e885c1633ad951a2d8168f80d36858af279d8b5fe2e19cf79eac15ecb9fdd364736f6c634300081e0033'
        self.contract_abi = [{'inputs': [{'internalType': 'uint256', 'name': 'LCG_MULTIPLIER', 'type': 'uint256'}, {'internalType': 'uint256', 'name': 'LCG_INCREMENT', 'type': 'uint256'}, {'internalType': 'uint256', 'name': 'LCG_MODULUS', 'type': 'uint256'}, {'internalType': 'uint256', 'name': '_currentState', 'type': 'uint256'}, {'internalType': 'uint256', 'name': '_counter', 'type': 'uint256'}], 'name': 'nextVal', 'outputs': [{'internalType': 'uint256', 'name': '', 'type': 'uint256'}], 'stateMutability': 'pure', 'type': 'function'}]
        self.deployed_contract = None

    def deploy_lcg_contract(self):
        self.deployed_contract = SmartContracts.deploy_contract(self.contract_bytes, self.contract_abi)

    def get_next(self, counter):
        print(f'\n[+] Calling nextVal() with _currentState={self.state}')
        self.state = self.deployed_contract.functions.nextVal(self.multiplier, self.increment, self.modulus, self.state, counter).call()
        print(f'  _counter = {counter}: Result = {self.state}')
        return self.state

class TripleXOROracle:
    def __init__(self):
        self.contract_bytes = '61030f61004d600b8282823980515f1a6073146041577f4e487b71000000000000000000000000000000000000000000000000000000005f525f60045260245ffd5b305f52607381538281f3fe7300000000000000000000000000000000000000003014608060405260043610610034575f3560e01c80636230075614610038575b5f5ffd5b610052600480360381019061004d919061023c565b610068565b60405161005f91906102c0565b60405180910390f35b5f5f845f1b90505f845f1b90505f61007f85610092565b9050818382181893505050509392505050565b5f5f8290506020815111156100ae5780515f525f5191506100b6565b602081015191505b50919050565b5f604051905090565b5f5ffd5b5f5ffd5b5f819050919050565b6100df816100cd565b81146100e9575f5ffd5b50565b5f813590506100fa816100d6565b92915050565b5f5ffd5b5f5ffd5b5f601f19601f8301169050919050565b7f4e487b71000000000000000000000000000000000000000000000000000000005f52604160045260245ffd5b61014e82610108565b810181811067ffffffffffffffff8211171561016d5761016c610118565b5b80604052505050565b5f61017f6100bc565b905061018b8282610145565b919050565b5f67ffffffffffffffff8211156101aa576101a9610118565b5b6101b382610108565b9050602081019050919050565b828183375f83830152505050565b5f6101e06101db84610190565b610176565b9050828152602081018484840111156101fc576101fb610104565b5b6102078482856101c0565b509392505050565b5f82601f83011261022357610222610100565b5b81356102338482602086016101ce565b91505092915050565b5f5f5f60608486031215610253576102526100c5565b5b5f610260868287016100ec565b9350506020610271868287016100ec565b925050604084013567ffffffffffffffff811115610292576102916100c9565b5b61029e8682870161020f565b9150509250925092565b5f819050919050565b6102ba816102a8565b82525050565b5f6020820190506102d35f8301846102b1565b9291505056fea26469706673582212203fc7e6cc4bf6a86689f458c2d70c565e7c776de95b401008e58ca499ace9ecb864736f6c634300081e0033'
        self.contract_abi = [{'inputs': [{'internalType': 'uint256', 'name': '_primeFromLcg', 'type': 'uint256'}, {'internalType': 'uint256', 'name': '_conversationTime', 'type': 'uint256'}, {'internalType': 'string', 'name': '_plaintext', 'type': 'string'}], 'name': 'encrypt', 'outputs': [{'internalType': 'bytes32', 'name': '', 'type': 'bytes32'}], 'stateMutability': 'pure', 'type': 'function'}]
        self.deployed_contract = None

    def deploy_triple_xor_contract(self):
        self.deployed_contract = SmartContracts.deploy_contract(self.contract_bytes, self.contract_abi)

    def encrypt(self, prime_from_lcg, conversation_time, plaintext_bytes):
        print(f'\n[+] Calling encrypt() with prime_from_lcg={prime_from_lcg}, time={conversation_time}, plaintext={plaintext_bytes}')
        ciphertext = self.deployed_contract.functions.encrypt(prime_from_lcg, conversation_time, plaintext_bytes).call()
        print(f'  _ciphertext = {ciphertext.hex()}')
        return ciphertext

class ChatLogic:
    def __init__(self):
        self.lcg_oracle = None
        self.xor_oracle = None
        self.rsa_key = None
        self.seed_hash = None
        self.super_safe_mode = False
        self.message_count = 0
        self.conversation_start_time = 0
        self.chat_history = []
        self._initialize_crypto_backend()

    def _get_system_artifact_hash(self):
        artifact = platform.node().encode('utf-8')
        hash_val = hashlib.sha256(artifact).digest()
        seed_hash = int.from_bytes(hash_val, 'little')
        print(f'[SETUP]  - Generated Seed {seed_hash}...')
        return seed_hash

    def _generate_primes_from_hash(self, seed_hash):
        primes = []
        current_hash_byte_length = (seed_hash.bit_length() + 7) // 8
        current_hash = seed_hash.to_bytes(current_hash_byte_length, 'little')
        print('[SETUP] Generating LCG parameters from system artifact...')
        iteration_limit = 10000
        iterations = 0
        while len(primes) < 3 and iterations < iteration_limit:
            current_hash = hashlib.sha256(current_hash).digest()
            candidate = int.from_bytes(current_hash, 'little')
            iterations += 1
            if candidate.bit_length() == 256 and isPrime(candidate):
                primes.append(candidate)
                print(f'[SETUP]  - Found parameter {len(primes)}: {str(candidate)[:20]}...')
        if len(primes) < 3:
            error_msg = '[!] Error: Could not find 3 primes within iteration limit.'
            print('Current Primes: ', primes)
            print(error_msg)
            exit()
        return (primes[0], primes[1], primes[2])

    def _initialize_crypto_backend(self):
        self.seed_hash = self._get_system_artifact_hash()
        m, c, n = self._generate_primes_from_hash(self.seed_hash)
        self.lcg_oracle = LCGOracle(m, c, n, self.seed_hash)
        self.lcg_oracle.deploy_lcg_contract()
        print('[SETUP] LCG Oracle is on-chain...')
        self.xor_oracle = TripleXOROracle()
        self.xor_oracle.deploy_triple_xor_contract()
        print('[SETUP] Triple XOR Oracle is on-chain...')
        print('[SETUP] Crypto backend initialized...')

    def generate_rsa_key_from_lcg(self):
        print('[RSA] Generating RSA key from on-chain LCG primes...')
        lcg_for_rsa = LCGOracle(self.lcg_oracle.multiplier, self.lcg_oracle.increment, self.lcg_oracle.modulus, self.seed_hash)
        lcg_for_rsa.deploy_lcg_contract()
        primes_arr = []
        rsa_msg_count = 0
        iteration_limit = 10000
        iterations = 0
        while len(primes_arr) < 8 and iterations < iteration_limit:
            candidate = lcg_for_rsa.get_next(rsa_msg_count)
            rsa_msg_count += 1
            iterations += 1
            if candidate.bit_length() == 256 and isPrime(candidate):
                primes_arr.append(candidate)
                print(f'[RSA]  - Found 256-bit prime #{len(primes_arr)}')
        print('Primes Array: ', primes_arr)
        if len(primes_arr) < 8:
            error_msg = '[RSA] Error: Could not find 8 primes within iteration limit.'
            print('Current Primes: ', primes_arr)
            print(error_msg)
            return error_msg
        n = 1
        for p_val in primes_arr:
            n *= p_val
        phi = 1
        for p_val in primes_arr:
            phi *= p_val - 1
        e = 65537
        if math.gcd(e, phi)!= 1:
            error_msg = '[RSA] Error: Public exponent e is not coprime with phi(n). Cannot generate key.'
            print(error_msg)
            return error_msg
        self.rsa_key = RSA.construct((n, e))
        try:
            with open('public.pem', 'wb') as f:
                pass  # postinserted
        except Exception as e:
                f.write(self.rsa_key.export_key('PEM'))
                    print('[RSA] Public key generated and saved to \'public.pem\'')
                    return 'Public key generated and saved successfully.'
                print(f'[RSA] Error saving key: {e}')
                return f'Error saving key: {e}'

    def process_message(self, plaintext):
        if self.conversation_start_time == 0:
            self.conversation_start_time = time.time()
        conversation_time = int(time.time() - self.conversation_start_time)
        if self.super_safe_mode and self.rsa_key:
            plaintext_bytes = plaintext.encode('utf-8')
            plaintext_enc = bytes_to_long(plaintext_bytes)
            _enc = pow(plaintext_enc, self.rsa_key.e, self.rsa_key.n)
            ciphertext = _enc.to_bytes(self.rsa_key.n.bit_length(), 'little').rstrip(b'\x00')
            encryption_mode = 'RSA'
            plaintext = '[ENCRYPTED]'
        else:  # inserted
            prime_from_lcg = self.lcg_oracle.get_next(self.message_count)
            ciphertext = self.xor_oracle.encrypt(prime_from_lcg, conversation_time, plaintext)
            encryption_mode = 'LCG-XOR'
        log_entry = {'conversation_time': conversation_time, 'mode': encryption_mode, 'plaintext': plaintext, 'ciphertext': ciphertext.hex()}
        self.chat_history.append(log_entry)
        self.message_count += 1
        self.save_chat_log()
        return (f'[{conversation_time}s] {plaintext}', f'[{conversation_time}s] {ciphertext.hex()}')

    def save_chat_log(self):
        try:
            with open('chat_log.json', 'w') as f:
                pass  # postinserted
        except Exception as e:
                json.dump(self.chat_history, f, indent=2)
                print(f'Error saving chat log: {e}')

class ChatApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('Chain of Demands - Secure Chat')
        self.geometry('1000x800')
        top_frame = tk.Frame(self, bd=5)
        top_frame.pack(fill='x')
        chat_frame = tk.Frame(self, bd=5)
        chat_frame.pack(expand=True, fill='both')
        input_frame = tk.Frame(self, bd=5)
        input_frame.pack(fill='x')
        tk.Label(top_frame, text='Connect to IP:').pack(side='left')
        self.ip_entry = tk.Entry(top_frame, width=20)
        self.ip_entry.insert(0, '127.0.0.1')
        self.ip_entry.pack(side='left', padx=5)
        self.connect_button = tk.Button(top_frame, text='Connect', command=self.connect_to_peer)
        self.connect_button.pack(side='left')
        self.load_files_button = tk.Button(top_frame, text='Last Convo', command=self.load_last_generated_files)
        self.load_files_button.pack(side='left', padx=10)
        self.web3_config_button = tk.Button(top_frame, text='Web3 Config', command=self.open_web3_config_window)
        self.web3_config_button.pack(side='left')
        self.status_label = tk.Label(top_frame, text='Status: Disconnected', fg='red')
        self.status_label.pack(side='left', padx=10)
        self.chat_box = scrolledtext.ScrolledText(chat_frame, state='disabled', wrap=tk.WORD, bg='#f0f0f0')
        self.chat_box.pack(expand=True, fill='both')
        self.msg_entry = tk.Entry(input_frame, width=60)
        self.msg_entry.pack(side='left', expand=True, fill='x', padx=5)
        self.msg_entry.bind('<Return>', self.send_message_event)
        self.msg_entry.config(state='disabled')
        self.send_button = tk.Button(input_frame, text='Send', command=self.send_message_event)
        self.send_button.pack(side='left')
        self.send_button.config(state='disabled')
        self.super_safe_var = BooleanVar()
        self.super_safe_check = Checkbutton(top_frame, text='Enable Super-Safe Encryption', variable=self.super_safe_var, command=self.toggle_super_safe)
        self.super_safe_check.pack(side='right', padx=10)
        self.logic = ChatLogic()

    def open_web3_config_window(self):
        config_window = Toplevel(self)
        config_window.title('Web3 Configuration')
        config_window.geometry('650x150')
        config_window.resizable(False, False)
        main_frame = tk.Frame(config_window, padx=10, pady=10)
        main_frame.pack(expand=True, fill='both')
        tk.Label(main_frame, text='RPC URL:').grid(row=0, column=0, sticky='w', pady=5)
        rpc_entry = tk.Entry(main_frame, width=60)
        rpc_entry.grid(row=0, column=1, sticky='ew')
        rpc_entry.insert(0, SmartContracts.rpc_url)
        tk.Label(main_frame, text='Private Key:').grid(row=1, column=0, sticky='w', pady=5)
        pk_entry = tk.Entry(main_frame, width=60)
        pk_entry.grid(row=1, column=1, sticky='ew')
        pk_entry.insert(0, SmartContracts.private_key)

        def save_and_close():
            new_rpc_url = rpc_entry.get().strip()
            new_pk = pk_entry.get().strip()
            if new_rpc_url and new_pk:
                SmartContracts.rpc_url = new_rpc_url
                SmartContracts.private_key = new_pk
                print(f'[CONFIG] Web3 RPC URL updated to: {new_rpc_url}')
                print('[CONFIG] Web3 Private Key updated.')
                messagebox.showinfo('Success', 'Web3 configuration has been updated.', parent=config_window)
                config_window.destroy()
            else:  # inserted
                messagebox.showerror('Error', 'Both fields are required.', parent=config_window)
        save_button = tk.Button(main_frame, text='Save & Close', command=save_and_close)
        save_button.grid(row=2, column=1, sticky='e', pady=10)
        config_window.transient(self)
        config_window.grab_set()
        self.wait_window(config_window)
        self.logic = ChatLogic()

    def connect_to_peer(self):
        ip = self.ip_entry.get()
        if ip:
            self.status_label.config(text=f'Status: Connected to {ip}', fg='green')
            self.display_message_in_box('--- Welcome to Secure Chat ---', 'system')
            self.display_message_in_box(f'[SYSTEM] Connection to {ip} established.\n', 'system')
            self.display_message_in_box('You are now talking with the ransomware operator.', 'system')
            self.display_message_in_box('--------------------------------------------------\n', 'system')
            self.msg_entry.config(state='normal')
            self.send_button.config(state='normal')

    def display_message_in_box(self, message, tag):
        self.chat_box.config(state='normal')
        self.chat_box.insert(tk.END, message + '\n', tag)
        self.chat_box.config(state='disabled')
        self.chat_box.see(tk.END)
        self.chat_box.tag_config('user', foreground='blue')
        self.chat_box.tag_config('peer', foreground='green')
        self.chat_box.tag_config('system', foreground='red')
        self.chat_box.tag_config('error', foreground='orange')

    def send_message_event(self, event=None):
        msg = self.msg_entry.get()
        if msg:
            self.display_message_in_box(f'You: {msg}', 'user')
            _, encrypted_msg_display = self.logic.process_message(msg)
            self.display_message_in_box(f'Peer (Encrypted): {encrypted_msg_display}', 'peer')
            self.msg_entry.delete(0, tk.END)

    def toggle_super_safe(self):
        if self.super_safe_var.get():
            self.logic.super_safe_mode = True
            self.display_message_in_box('[SYSTEM] Super-Safe mode enabled. Generating RSA key...', 'system')
            Thread(target=self.generate_rsa_and_update_gui, daemon=True).start()
        else:  # inserted
            self.logic.super_safe_mode = False
            self.display_message_in_box('[SYSTEM] Super-Safe mode disabled. Reverting to standard LCG-XOR.', 'system')

    def generate_rsa_and_update_gui(self):
        result_msg = self.logic.generate_rsa_key_from_lcg()
        self.display_message_in_box(f'[SYSTEM] {result_msg}', 'system')

    def load_last_generated_files(self):
        files_window = Toplevel(self)
        files_window.title('Generated Files')
        files_window.geometry('700x500')
        tk.Label(files_window, text='chat_log.json', font=('Helvetica', 12, 'bold')).pack(pady=(10, 0))
        json_text_area = scrolledtext.ScrolledText(files_window, wrap=tk.WORD, height=15)
        json_text_area.pack(expand=True, fill='both', padx=10, pady=5)
        try:
            json_path = resource_path('chat_log.json')
            with open(json_path, 'r') as f:
                pass  # postinserted
        except FileNotFoundError:
                json_data = json.load(f)
                pretty_json = json.dumps(json_data, indent=2)
                json_text_area.insert(tk.END, pretty_json)
                else:  # inserted
                    json_text_area.config(state='disabled')
                    tk.Label(files_window, text='public.pem', font=('Helvetica', 12, 'bold')).pack(pady=(10, 0))
                    pem_text_area = scrolledtext.ScrolledText(files_window, wrap=tk.WORD, height=8)
                    pem_text_area.pack(expand=True, fill='both', padx=10, pady=(5, 10))
                    try:
                        pem_path = resource_path('public.pem')
                        with open(pem_path, 'r') as f:
                            pass  # postinserted
                    except FileNotFoundError:
                            pem_data = f.read()
                            pem_text_area.insert(tk.END, pem_data)
                            else:  # inserted
                                pem_text_area.config(state='disabled')
                json_text_area.insert(tk.END, 'chat_log.json not found.\n\nSend a message to generate it.')
            except Exception as e:
                json_text_area.insert(tk.END, f'Error reading chat_log.json:\n{e}')
            else:  # inserted
                pass
                pem_text_area.insert(tk.END, 'public.pem not found.\n\nEnable \'Super-Safe Encryption\' to generate it.')
            except Exception as e:
                pem_text_area.insert(tk.END, f'Error reading public.pem:\n{e}')
            else:  # inserted
                pass
if __name__ == '__main__':
    app = ChatApp()
    app.mainloop()
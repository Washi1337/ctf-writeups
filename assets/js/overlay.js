
$(document).ready(function() 
{
    let overlay = $(".overlay");
    $(".content-container > p > img").click(function()
    {
        overlay.fadeIn("fast");
        overlay.find("img").attr("src", $(this).attr("src"));
    });

    overlay.click(function() 
    {
        overlay.fadeOut("fast");
    });
});
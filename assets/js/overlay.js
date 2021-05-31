
$(document).ready(function() 
{
    let overlay = $(".overlay");
    $(".content-container > p > img").click(function()
    {
        overlay.find("img").attr("src", $(this).attr("src"));
        overlay.fadeIn("fast");
    });

    overlay.click(function() 
    {
        overlay.fadeOut("fast");
    });
});
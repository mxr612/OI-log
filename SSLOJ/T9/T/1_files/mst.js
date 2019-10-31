/// <reference path="jquery-1.10.2.min.js" />
/// <reference path="../layer/layer.js" />

function clearsto()
{
    var sto = window.localStorage;
    sto.removeItem("ojuser");
    sto.removeItem("ojpsw");
    return true;
}

$(function () {
    $("#div_sidebar ul li").hover(function () {
        $(this).find("p").stop().fadeIn(400);
    }, function () {
        $(this).find("p").stop().fadeOut(200);
    });

    $("#div_top #log").click(function () {
        layer.open({
            type: 2,
            title: '登录',
            shadeClose: true,
            shade: 0.8,
            area: ['580px', '380px'],
            content: 'login.html'
        });
    });

    $("#div_top #reg").click(function () {
        layer.open({
            type: 2,
            title: '注册',
            shadeClose: true,
            shade: 0.8,
            area: ['580px', '380px'],
            content: 'reguser.aspx'  
        });
    });

    var s = $("#div_top #div_img img").hide().attr("src");
    var sessionsto = window.sessionStorage;
    var urls = "url(../" + s + ") no-repeat center center";
    sessionsto.setItem("headimg", urls);
    $("#div_top #div_img").css({ "background": urls ,"background-size":"100%"});
});
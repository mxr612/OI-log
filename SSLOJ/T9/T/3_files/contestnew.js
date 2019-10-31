/// <reference path="jquery-1.10.2.min.js" />
/// <reference path="../layer/layer.js" />


$(function () {
    $("#div_content .div_cons #ContentPlaceHolder1_div_proset #btn_uppro").hide();
    $("#div_content .div_navs :radio").each(function () {
        if ($(this).prop("checked"))
            $(this).next().addClass("sel");
    });

    $("#div_content .div_navs label").eq(2).click(function () {
        if ($(this).hasClass("sel"))
        {
            $("#div_content .div_cons #ContentPlaceHolder1_div_proset #pro_lst").fadeIn(300);
            $("#div_content .div_cons #ContentPlaceHolder1_div_proset #pro_detail").fadeOut(300);
            $("#div_content .div_cons #ContentPlaceHolder1_div_proset #btn_uppro").hide();
        }    
    });

    $("#div_content .div_cons #ContentPlaceHolder1_div_proset table span[pid]").click(function () {
        $("#div_content .div_cons #ContentPlaceHolder1_div_proset #pro_lst").hide();
        var pid = $(this).attr("pid");
        $.post("../ajax/getproblem.ashx", { "pid": pid }, function (data) {
            $("#div_content .div_cons #ContentPlaceHolder1_div_proset #pro_detail").fadeIn(1000).html(data);
            $("#div_content .div_cons #ContentPlaceHolder1_div_proset #btn_uppro").show();
        });
    });

    $("#div_content .div_cons #ContentPlaceHolder1_div_proset #btn_uppro").click(function () {
        var pid = $("#div_content .div_cons #ContentPlaceHolder1_div_proset #pro_detail #header").attr("pid");
        $.post("../ajax/checksubmit.ashx", { pid: pid ,cid:GetQueryString("cid")}, function (data) {
            if (data == "no")
                layer.msg("10秒内不能再次提交", {
                    icon: 5,
                    skin: 'layui-layer-molv'
                });
            else if(data=="nologin")
            {
                layer.msg("请先登录", {
                    icon: 5,
                    skin: 'layui-layer-molv'
                });
            }
            else if(data=="notime")
            {
                layer.msg("还未到提交时间", {
                    icon: 5,
                    skin: 'layui-layer-molv'
                });
            }
            else
                //window.location.href = data;
                layer.open({
                    type: 2,
                    area: ['90%', '100%'],
                    fixed: false, //不固定
                    maxmin: true,
                    title: '提交程序',
                    content: data
                });
        });
    });

    //拷贝到剪贴板
    var clipboard = new Clipboard('.s_copy_in');

    clipboard.on('success', function (e) {
        $(".s_copy_in").css({ "background": "blue" }).text("复制成功");
        setTimeout(function () {
            $(".s_copy_in").css("background", "#e67e22").text("复制");
        }, 300);
    });

    clipboard = new Clipboard('.s_copy_out');
    clipboard.on('success', function (e) {
        $(".s_copy_out").css({ "background": "blue" }).text("复制成功");
        setTimeout(function () {
            $(".s_copy_out").css("background", "#e67e22").text("复制");
        }, 300);
    });
})
function GetQueryString(name)
{
    var reg = new RegExp("(^|&)"+ name +"=([^&]*)(&|$)");
    var r = window.location.search.substr(1).match(reg);
    if(r!=null)return  unescape(r[2]); 
    return null;
}

function tips1() {
    layer.msg("已经申请过了，请不要重复申请", { icon: 5 });
    $("#ContentPlaceHolder1_btn_apply").addClass("disabled");
}

function tips2() {
    layer.msg("申请成功，请准时参加比赛！", { icon: 6 });
    $("#ContentPlaceHolder1_btn_apply").addClass("disabled");
}
function tips3() {
    layer.msg("申请成功，请等待审核！", { icon: 6 });
    $("#ContentPlaceHolder1_btn_apply").addClass("disabled");
}
/// <reference path="jquery-1.10.2.min.js" />

var tag=1;
function sortNumberAS(a, b)
{
    return a - b    
}
function sortNumberDesc(a, b)
{
    return b-a
}
                
function SortTable(obj){
    var col_len = document.getElementsByTagName("th").length;
    var row_len = document.getElementsByTagName("tr").length - 1;
    var tdArrays = new Array();
    for (var i = 0; i < col_len; i++)
    {
        tdArrays[i] = new Array();
        var _tds = document.getElementsByName("td" + i.toString());
        for (var j = 0; j < _tds.length; j++) {
            tdArrays[i].push(_tds[j].innerHTML);
        }
    }
    var tds=document.getElementsByName("td"+obj.id.substr(2,1));
    var columnArray=[];
    for(var i=0;i<tds.length;i++){
        columnArray.push(tds[i].innerHTML);
    }
    var orginArray=[];
    for(var i=0;i<columnArray.length;i++){
        orginArray.push(columnArray[i]);
    }
    if(obj.className=="desc"){
        columnArray.sort(sortNumberAS);               //排序后的新值
        obj.className="as";
    }else{
        columnArray.sort(sortNumberDesc);               //排序后的新值
        obj.className="desc";
    }
                     
    for(var i=0;i<columnArray.length;i++){
        for(var j=0;j<orginArray.length;j++){
            if(orginArray[j]==columnArray[i]){
                for(var k=0;k<col_len;k++)
                  document.getElementsByName("td"+k.toString())[i].innerHTML=tdArrays[k][j];
                orginArray[j]=null;
                break;
            }
        }
    }
}
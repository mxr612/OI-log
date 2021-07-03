program sort;
var n,i,j:integer;
    temp1,temp2,s:integer;
    xh,cj,mc:array[1..300] of integer;
begin
  assign(input,'sort.in');
  assign(output,'sort.out');
  reset(input);
  rewrite(output);
  fillchar(xh,sizeof(xh),0);
  fillchar(cj,sizeof(cj),0);
  fillchar(mc,sizeof(mc),0);
  readln(n);
  for i:=1 to n do
   readln(xh[i],cj[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
    begin
     if cj[i]<cj[j] then
       begin
         temp1:=xh[i]; xh[i]:=xh[j]; xh[j]:=temp1;
         temp2:=cj[i]; cj[i]:=cj[j]; cj[j]:=temp2;
       end;
     if (cj[i]=cj[j]) and (xh[i]>xh[j]) then
       begin
         temp1:=xh[i]; xh[i]:=xh[j]; xh[j]:=temp1;
         temp2:=cj[i]; cj[i]:=cj[j]; cj[j]:=temp2;
       end;
   end;
   temp1:=1; mc[1]:=1; s:=1;
   for i:=2 to n do
    if cj[i]=cj[i-1] then
     begin
       mc[i]:=temp1; s:=s+1;
     end
     else
      begin
        s:=s+1;
        temp1:=s;
        mc[i]:=temp1;
      end;
  for i:=1 to n do
    writeln(xh[i],' ',cj[i],' ',mc[i]);
  close(input);
  close(output);
end.
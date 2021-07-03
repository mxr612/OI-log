Program sort;
type rec=record
      id:integer;
      grade:integer;
      pai:integer;
     end;
var lists:array[1..201] of rec;
    i,j,k,x,y,n,nowgrade,infact:integer;
    temp:rec;
begin
assign(input,'sort.in');
reset(input);
assign(output,'sort.out');
rewrite(output);
 readln(n);
 for i:=1 to n do begin read(lists[i].id); read(lists[i].grade); end;
 {sort}
 for i:=1 to n do
  for j:=i to n do
   begin
    if (lists[j].grade > lists[i].grade) then begin temp:=lists[i]; lists[i]:=lists[j]; lists[j]:=temp; end;
    if (lists[j].grade = lists[i].grade) and (lists[j].id<lists[i].id) then begin temp:=lists[i]; lists[i]:=lists[j]; lists[j]:=temp; end;
   end;
 {start pai}
 for i:=1 to n do lists[i].pai:=i;
 {output}
 write(lists[1].id,' '); write(lists[1].grade,' '); write(lists[1].pai); writeln;
 for i:=2 to n do
 begin
  if lists[i].grade=lists[i-1].grade then
   begin
    write(lists[i].id,' ');
    write(lists[i].grade,' ');
    write(lists[i-1].pai);
    lists[i].pai:=lists[i-1].pai;
    writeln;
   end
   else
   begin
    write(lists[i].id,' ');
    write(lists[i].grade,' ');
    write(lists[i].pai);
    writeln;
   end;
 end;
close(input);
close(output);
end.
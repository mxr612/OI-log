program x02;
type cd=record
    id,g,ranks:integer;
end;
var i,j,k,n:integer;
    stu:array[0..600]of cd;
    t:cd;
begin
   assign(input,'sort.in');
   reset(input);
   assign(output,'sort.out');
   rewrite(output);

   readln(n);
   for i:=1 to n do with stu[i] do readln(id,g);

   for i:=1 to n do for j:=i+1 to n do begin
       if stu[i].g < stu[j].g then begin
          t:=stu[i]; stu[i]:=stu[j]; stu[j]:=t;
       end;
       if (stu[i].g=stu[j].g)and(stu[i].id>stu[j].id) then begin
          t:=stu[i]; stu[i]:=stu[j]; stu[j]:=t;
       end;
   end;

   stu[1].ranks:=1;
   for i:=2 to n do begin
     if stu[i].g = stu[i-1].g then stu[i].ranks:=stu[i-1].ranks else stu[i].ranks:=i;
   end;

   for i:=1 to n do with stu[i] do writeln(id,' ',g,' ',ranks);
   close(input);
   close(output);
end.
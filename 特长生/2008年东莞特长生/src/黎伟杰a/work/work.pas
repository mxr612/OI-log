program work(input,output);
var
    a:array[0..1500]of boolean ;
    b:array[0..1500,1..1000]of integer;
    c:array[0..1500]of integer;
    d:array[0..1500]of integer;
    n,i,j:integer;

    x,y,ti:integer;
    las,zha:integer;

procedure st(p:integer);
var
o:integer;
  f:boolean;
begin



       if a[p] then begin

            f:=false;
            for o:=1 to c[p] do  begin
            if (d[p]+b[p,o])<(d[p+b[p,o]])then d[p+b[p,o]]:=d[p]+b[p,o];
             st(p+b[p,o]);
            end;
       end
       else begin inc(p); if d[p]<=d[p-1] then d[p]:=d[p-1];end;st(p);end;



end;
begin
   assign(input,'work.in');
   assign(output,'work.out');
   reset(input);
   rewrite(output);
   las:=0;
   fillchar(a,sizeof(a),false);
   fillchar(b,sizeof(b),0);
   fillchar(c,sizeof(c),0);

   read(n);
   for i:=1 to n do
   begin
     read(ti);read(x);read(y);
     for j:=x to (y-ti) do begin inc(c[j]);a[j]:=true;b[j,c[j]]:=ti;end;
     if y>las then las:=y;
   end;
   for i:=0 to las do d[i]:=1600;  d[0]:=0;
{   repeat

       if a[i] then begin
            if f then  if d[i-1]<d[i] then d[i]:=d[i-1];
            f:=false;
            for j:=1 to c[i] do
            if (d[i]+b[i,j])<(d[i+b[i,j]])then d[i+b[i,j]]:=d[i]+b[i,j];
       end
       else begin d[i]:=d[i-1];f:=true;end;
   until i=las;}
   st(0);
   write(d[las]);
   close(input);
   close(output);
end.
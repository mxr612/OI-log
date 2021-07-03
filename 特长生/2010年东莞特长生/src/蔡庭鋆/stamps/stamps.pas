program x04;
var a,b,i,j,k,k1,m,t,n,freesp:longint;
    st:array[1..200]of integer;
    sp:array[1..100]of integer;
begin
   assign(input,'stamps.in');
   reset(input);
   assign(output,'stamps.out');
   rewrite(output);

   readln(n);  readln(m);
   for i:=1 to m do readln(st[i]);

   for i:=1 to m do for j:=i+1 to m do if st[i]<st[j] then begin
      t:=st[i]; st[i]:=st[j]; st[j]:=t;
   end;
   while true do begin
      inc(k);   k1:=k;   freesp:=n;
      if (k1 div st[1])> n then break;
      for i:=1 to m do begin
         a := k1 div st[i];
         b := k1 mod st[i];
         freesp := freesp - a;
         k1:=b;   if (k1=0) or (freesp<0) then break;
      end;
      if freesp<0 then begin k:=k-1; break; end;
   end;
   writeln(k);

   close(input);
   close(output);
end.

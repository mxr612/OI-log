const
   oo=maxlongint;
   maxn=50000;
   maxm=100;
var
   f:array[0..maxn]of boolean;
   b:array[0..maxn]of longint;
   a:array[1..maxm]of longint;
   n,m,i,j:longint;
function min(x,y:longint):longint;
begin
   min:=x;
   if x>y then min:=y
end;
begin
   assign(input,'stamps.in');reset(input);
   assign(output,'stamps.out');rewrite(output);

   readln(n);
   readln(m);
   for i:=1 to m do readln(a[i]);

   for i:=1 to maxn do b[i]:=oo;
   f[0]:=true;
   j:=0;
   while f[j] and (b[j]<=n) do
   begin
      for i:=1 to m do
      begin
         f[j+a[i]]:=true;
         b[j+a[i]]:=min(b[j+a[i]],b[j]+1)
      end;
      inc(j)
   end;

   writeln(j-1);

   close(input);close(output)
end.


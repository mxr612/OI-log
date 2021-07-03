var a,b:string;
    e,f,g,h,i,j,k,n,q,p,d,c:longint;
    l,m:array[1..500] of longint;
procedure gaojing;
begin f:=length(a);k:=0;
      for h:=1 to f+1 do
             l[h]:=0;
      for g:=f downto 1 do
      begin
            k:=k+1;
            h:=ord(a[g])-48;
            l[k]:=l[k]+h+h;
            if l[k]>9 then begin l[k+1]:=1;l[k]:=l[k] mod 10;end;
            a:='';
      end;
      for j:=1 to k+1 do
             a:=chr(l[j]+48)+a;
            while a[1]='0' do
              delete(a,1,1);
end;
procedure jia;
begin if length(a)<length(b) then f:=length(a)
                             else f:=length(b);
      k:=0;
      for h:=1 to f+1 do
             m[h]:=0;
      for g:=f downto 1 do
      begin
            k:=k+1;
            h:=ord(a[g])-48;
            c:=ord(b[g])-48;
            m[k]:=m[k]+h+c;
            if m[k]>9 then begin m[k+1]:=1;m[k]:=m[k] mod 10;end;
            b:='';
      end;
      for j:=1 to k+1 do
             b:=chr(m[j]+48)+b;
            while (b[1]='0')and(b<>'') do
              delete(b,1,1);
end;
begin assign(input,'land.in');
      assign(output,'land.out');
      reset(input);rewrite(output);
      read(n);a:='1';b:=a;
      for e:=1 to n*n-1 do
      begin
            gaojing;
            jia; end;
      write(b);
      close(input);close(output);
end.
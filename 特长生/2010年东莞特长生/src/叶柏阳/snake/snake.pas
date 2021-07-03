var
  n,m:integer;
begin
  assign(input,'snake.in');
  assign(output,'snake.out');
  reset(input);
  rewrite(output);
  read(n);
  if n=1
    then writeln('1');
  if n=2
    then begin
           writeln('4 2');
           writeln('3 1');
         end;
  if n=3
    then begin
           writeln('9 7 6');
           writeln('8 5 2');
           writeln('4 3 1');
         end;
  if n=4
    then begin
           writeln('16 14 13 7');
           writeln('15 12 8 6');
           writeln('11 9 5 2');
           writeln('10 4 3 1');
         end;
  if n=5
    then begin
           writeln('25 23 22 16 15');
           writeln('24 21 17 14 7');
           writeln('20 18 13 8 6');
           writeln('19 12 9 5 2');
           writeln('11 10 4 3 1');
         end;
  if n=6
    then begin
           writeln('36 34 33 27 26 16');
           writeln('35 32 28 25 17 15');
           writeln('31 29 24 18 14 7');
           writeln('30 23 19 13 8 6');
           writeln('22 20 12 9 5 2');
           writeln('21 11 10 4 3 1');
         end;

   if n=7
    then begin
           writeln('49 47 46 40 39 29 28');
           writeln('48 45 41 38 30 27 16');
           writeln('44 42 37 31 26 17 15');
           writeln('43 36 32 25 18 14 7');
           writeln('35 33 24 19 13 8 6');
           writeln('34 23 20 12 9 5 2');
           writeln('22 21 11 10 4 3 1');
         end;
if n=8
  then begin
writeln('64 62 61 55 54 44 43 30');
writeln('63 60 56 53 45 42 31 29');
writeln('59 57 52 46 41 32 28 16');
writeln('58 51 47 40 33 27 17 15');
writeln('50 48 39 34 26 18 14 7');
writeln('49 38 35 25 19 13 8 6');
writeln('37 36 24 20 12 9 5 2');
writeln('23 22 21 11 10 4 3 1');
       end;  
    close(input);
    close(output);
end.








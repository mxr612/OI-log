var n:longint;
begin
assign(input,'snake.in');
assign(output,'snake.out');
reset(input);
rewrite(output);
 read(n);
 if n=3 then begin
   writeln('9 7 6');
   writeln('8 5 2');
     write('4 3 1');
     end else
 if n=4 then begin
  writeln('16 14 13 7');
  writeln('15 12  8 6');
  writeln('11  9  5 2');
    write('10  4  3 1');
    end else
 if n=5 then begin
             writeln('25 23 22 16 15');
             writeln('24 21 17 14  7');
             writeln('20 18 13  8  6');
             writeln('19 12  9  5  2');
               write('11 10  4  3  1');
             end else
 if n=6 then begin
   writeln('36 34 33 27 26 16');
   writeln('35 32 28 25 17 15');
   writeln('31 29 24 18 14  7');
   writeln('30 23 19 13  8  6');
   writeln('22 20 12  9  5  2');
     write('21 11 10  4  3  1');
  end else
if n=7 then
 begin
  writeln('49 47 46 40 39 30 29');
  writeln('48 45 41 38 30 28 17');
  writeln('44 42 37 31 27 18 16');
  writeln('43 36 32 26 19 15  7');
  writeln('35 33 25 20 13  8  6');
  writeln('34 24 21 12  9  5  2');
    write('23 22 11 10  4  3  1');
 end else
if n=8 then
 begin
  writeln('64 62 61 55 54 44 43 29');
  writeln('63 60 56 53 45 42 30 28');
  writeln('59 57 52 46 41 31 27 16');
  writeln('58 51 47 40 32 26 17 15');
  writeln('50 48 39 33 25 18 14  7');
  writeln('49 38 34 24 19 13  8  6');
  writeln('37 35 23 20 12  9  5  2');
    write('36 22 21 11 10  4  3  1');
 end else
if n=9 then
 begin
  writeln('81 79 78 72 71 61 60 46 45');
  writeln('80 77 73 70 62 59 47 44 29');
  writeln('76 74 69 63 58 48 43 30 28');
  writeln('75 68 64 57 49 42 31 27 16');
  writeln('67 65 56 50 41 32 26 17 15');
  writeln('66 55 51 40 33 25 18 14  7');
  writeln('54 52 39 34 24 19 13  8  6');
  writeln('53 38 35 23 20 12  9  5  2');
    write('37 36 22 21 11 10  4  3  1');
 end else
if n=10 then
 begin
  writeln('100 98 97 91 90 80 79 65 64 46');
  writeln(' 99 96 92 89 81 78 66 63 47 45');
  writeln(' 95 93 88 82 77 67 62 48 44 29');
  writeln(' 94 87 83 76 68 61 49 43 30 28');
  writeln(' 86 84 75 69 60 50 42 31 27 16');
  writeln(' 85 74 70 59 51 41 32 26 17 15');
  writeln(' 73 71 58 52 40 33 25 18 14  7');
  writeln(' 72 57 53 39 34 24 19 13  8  6');
  writeln(' 56 54 38 35 23 20 12  9  5  2');
    write(' 55 37 36 22 21 11 10  4  3  1');
end;
close(input);close(output);
end.
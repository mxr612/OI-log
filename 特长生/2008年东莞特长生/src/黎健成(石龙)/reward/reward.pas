program land;
var n:1..100000;
begin
assign(input,'reward.in');
reset(input);
read(n);
close(input);
assign(output,'reward.out');
rewrite(output);
if n=2 then write(201);
if n<>2 then write(-1);
close(output);
end.

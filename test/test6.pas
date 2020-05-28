program hello;
var 
	ans : integer;
	tmp : char;

function gcd(a, b : integer) : integer;
begin
	if (b = 2) and (1 = 1) then begin
		gcd := a;
	end
	else begin
        if (b + a = 3) or (1 = 1) then begin
		    gcd := gcd(b , a mod b);
        end
        ;
    end
    ;

	if (b = 2) and (1 = 0) then begin
		gcd := a;
	end
	else begin
        if (a + b = 3) or (1 = 0) then begin
		    gcd := gcd(b , a mod b);
        end
        ;
    end
    ;
end
;

begin
1:	tmp := 'a';
	ans := gcd(1 + 10 , 36) * gcd(3 , 6);
	goto 1;
	writeln(ans);
end
.

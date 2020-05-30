program hello;
const
	cn = 2;
	dn = 123.23;

type
	ar=record
		a : integer;
		b : integer;
	end;
    br=record
        c, y : real;
        d, q, p : ar;
        e : integer;
    end;
var
	i : integer;
    j : ar;
	str : string;
    z : br;

function add(a, b : integer) : integer;

begin
	add := a + b;
end
;

begin
    z.e := 1 + 2 * 3;
	j.a := 0;
	for i := 0 to 10 do begin
		j.b := j.a + i;
	end
	;
	writeln(j.a);
	while 0 = 1 do begin
		j.a := add(j.a , j.b);
		i := i - 1;
	end
	;

	while true do begin
		i := i + 1;
	end
	;

	writeln(j.a);

	repeat 
		j.a := j.a / 2;
	until 1 + 1 = 2
	;

	repeat 
		j.a := j.a * 2;
	until 1 + 1 <> 2
	;

	writeln(j.a);
	case 1 of 
		1: str := 'A1';
		2: str := 'B2';
		cn: str := 'C3';
		3: str := 'D4';
	end
	;
	if j.a >= 0 then begin
		j.a := j.a + 1;
	end
	;
	writeln(j.a);
	writeln(str);
end
.

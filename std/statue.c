//#pragma save_binary

// Object for linkdead user, created by Kyoko.

#include <mudlib.h>

inherit OBJECT;

#define LONG_DESCRIPTION_D "/cmds/std/_look"
void create()
{
	set_name( "statue", "雕像" );
	set_short( "一座不知名的雕像" );
	set_long("一座不知名的雕像，不知是谁刻的。\n");
	set("weight", 20);
	set("prevent_get", 1);
	set("no_attack", 1);
}

string long_description(object ob)
{
	object *inv;
	int i, first;
	string a1, a2, tmp, reg, race, raceat, short, gender, genat;

	reg = (string)ob->query("long");
	if (!reg) reg = "";

		race = ob->query("race");
		raceat = to_chinese(race);
		gender = (string)ob->query("gender");
		genat = to_chinese(subjective(gender));

	i = sizeof(inv = all_inventory(ob));
	while (i--) {
		if ( tmp = inv[i]->query("extra_look")) {
			while(sscanf(tmp, "%s$N%s", a1, a2) > 1)
			  tmp = sprintf("%s%s%s", a1, ob->query("c_name"), a2);
			reg += tmp;
			} 
		}
    
	if( sizeof(inv) ) {
		for(i=0, first=1; i<sizeof(inv); i++) {
			short = (string)inv[i]->query("short");
			if (short) {
				if( inv[i]->query("equipped") && 
				   ((string)inv[i]->query("type") != "shield") )
					if( first ) {
						first = 0;
						reg += genat + "身上穿著 : ";
						reg += short;
						} 
				else
				reg += ", " + short;
			}
		}
		if( !first )
		  reg += "。\n" ;
        for(i=0, first=1; i<sizeof(inv); i++) {
			short = (string)inv[i]->query("short");
			if (short) {
				if( inv[i]->query("wielded") || 
				    ( inv[i]->query("equipped") && 
				     ((string)inv[i]->query("type") == "shield" )) )
				  if( first ) {
				    first = 0;
				    reg += genat + "手上拿著 : ";
				    reg += short;
				  }
				else
				reg += ", " + short;
			}
		}
		if( !first )
		reg += "。\n";
	}
		
	if (stringp (race) && race != "")
		reg += genat + "的种族是" + raceat + "。\n";

	if( sizeof(inv) ) {
		first = 1;
		for(i=0; i<sizeof(inv); i++) {
			short = (string)inv[i]->query("short");
			if(short) {
				if( inv[i]->query("wielded") || inv[i]->query("equipped") )
				  continue;
				if( first ) {
				  reg += genat + "身上携带著:\n";
					first = 0;
				}
				reg += "    " + short + ".\n";
			}
		}
	}
	return reg;
}

void assign(object who)
{
	set_short((string)who->query("c_name")+"的雕像");
	set_long("这是一座"+(string)who->query("c_name")+
		"的雕像，刻的栩栩如生。\n"+long_description( who)
	);
//	add("id", who->query("id") );
}

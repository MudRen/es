#include "../oldcat.h"

inherit MONSTER;

string *str1=({ "����","����","����","������","�ؾ�","������","������","����","ħ��"});
string *str2=({ "human","elf","dwarf","orc","gnome","halfing","lizardman","imp","daemon"});

void create()
{
        int i;

	::create();
	set_level(12);
	i=random(sizeof(str1));
	set_name( str2[i] + " adventurer", str1[i] + "ð����" );
	add( "id", ({ str2[i], "adventurer" }) );
	set_short( str1[i]+ "ð����" );
	set_long(
	  "�����������"+str1[i]+"ð������սս������̽�����Σ�յ�����\n"
	);
	set( "gender", ({"male", "female" })[random(2)] );
	set( "race", str2[i] );
	set( "alignment", random(600)-300 );
        set_natural_armor(55,20);
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "kar", 15 );
        set( "alt_corpse",OOBJ"adv_corpse.c");
	set( "wealth/silver", 50 );
        set_skill("jousting",50);
        set_skill("parry",50);
        set_skill("dodge",50);
        
        wield_weapon(OWEAPON"lance");
}

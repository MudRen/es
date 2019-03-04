#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "rat", "����" );
	set_short( "a rat", "����" );
	set_long(
		"A small rat. It looks pretty hungry.\n",
		"һֻ��С�����󣬿�����������˺ܾá�\n"
	);
	set_perm_stat("dex", 3 );
	set_perm_stat("str", 2 );

	set_c_verbs( ({ "%s��צ����ץ%s", "%s������%sҧ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );

	set( "unit", "ֻ" );
	set( "natural_armor_class", 8 );
#include <replace_mob.h>
}

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "mew", "��Ÿ" );
	add( "id", ({ "mew" }) );
	set_short( "��Ÿ" );
	set_long("����һ�ֺ���\n");	
	set("unit","ֻ");
    set( "alignment", -50 );
	set_perm_stat( "dex", 4 );
	set_c_verbs( ({ "%s���¸��壬�������%s", "%s��צ����%sץ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "���" }) );
#include <replace_mob.h>
}

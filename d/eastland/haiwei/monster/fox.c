#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "fox", "����" );
	add( "id", ({ "fox" }) );
	set_short( "����" );
	set_long("����һ�ִ����кܽƻ��Ķ�����������������ɰ��ġ�\n");	
	set("unit","ֻ");
    set( "alignment", 200 );
	set_perm_stat( "dex", 10 );
	set_c_verbs( ({ "%s������ҧ��%s", "%s��ǰצ��%sץ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ų�","β��" }) );
#include <replace_mob.h>
}

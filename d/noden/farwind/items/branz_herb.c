#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
	set_name( "branz herb", "������ҩ��" );
	add( "id", ({ "herb" }) );
	set_short( "������ҩ��" );
	set_long(
		"��˵����Ѳ�����ҩ�ݷ�(apply)���˿��ϣ���ʹ�˿ڻָ��ñȽϿ졣\n"
	);
	set( "unit", "��" );
	set( "heal_apply", 2 );
	set( "duration", 10 );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}

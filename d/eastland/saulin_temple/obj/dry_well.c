#include "../saulin_temple.h"

inherit CONTAINER;

void create()
{
	object gourd;
	::create();
	set_name("Well", "��");
	set_short("��");
	set("id", ({"well"}) );
	set_c_open_long(@C_LONG
���ߵ�����������һ������ѽ! ��ˮ���Ѿ�Ǭ�ˣ�����Ǭ�ѵ������γ�һ����
�ݺ�Ĵ�졣��Ӧ�ÿ�����(climb)�¾��׿�����
C_LONG
	);
	
	set("prevent_get",1);
	set("max_load",500);
	set("prevent_insert",1);
	gourd = new( SAULIN_OBJ"gourd" );
	gourd->move( this_object() );
}

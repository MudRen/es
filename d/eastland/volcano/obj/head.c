#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "head", "��ͷ" );
	set_short( "��ͷ" );
	set_long(
		"����һ��ð���ߵ�ͷ��\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
        call_out("disappear",300,this_object());
}

void disappear(object ob)
{
  object owner;
  owner=environment(this_object());
  if (!owner)
    printf("�����������ͷ��ʱ����绯���ˡ�\n"); 
  remove(); 
}

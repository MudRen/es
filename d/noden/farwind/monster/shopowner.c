#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 10 );
	set_name( "shop owner", "�̵��ϰ�" );
	add( "id", ({ "owner" }) );
	set_short( "�̵��ϰ�" );
	set_long(@C_LONG
�̵��ϰ��Ǹ������ˣ�ͷ��΢ͺ�����ϳ�������һ�������Ц
�ݡ�����Է��ĵİ���Ҫ��������Ʒ��������һ����������Ȥ��
�Ǽ�������ϡ��Źֵ���Ʒ��
C_LONG
    	       );
	set( "no_attack", 1 );
	set( "gender", "male" );
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "�̵��ϰ��Ц��: л��! �׳�!\n"
        "( �̵��ϰ��"+item->query("c_name")+"������! )\n" );
   item->remove();
   return 1;
}

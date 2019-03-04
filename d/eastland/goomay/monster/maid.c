
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "maid", "�Ů" );
        set_short("�Ů");
        set("unit","��");
        set_long(
@C_LONG
    ����һλ�ܿɰ���СŮ����������Ѿͷ�٣�һ��ʲ�ᶼ���µ����ӡ�
��������ǰ��ɨ��˳�����������Ů���˿����Ż������������������
��СŮ����һ����ϲ��һЩ������������
C_LONG
);
        set ("gender", "female");
        set ("race", "human");
		set("no_attack",1);
}
void init()
{
        add_action( "kill_me", "kill");
}

int kill_me(string arg)
{
  if (arg=="maid")
	{
	tell_object(this_player(),
		"�Ů�����ص� �� ��� �����ò�Ҫ�� !! �۸������С�𣿳�ȥ��ȥ !!��\n"
		"˵���Ͱ����Ƴ����⡣\n" 
		);
      this_player()->move_player( Goomay"rich_house", "SNEAK" );
        tell_room( Goomay"rich_house", 
         this_player()->query("c_name") + "���˴�����¥���˳�����\n"
        ,this_player() );
        return 1;
	}
	else 
	this_player()->command("kill "+arg);

}

int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="blue pearl" && name != "pearl ring") ) return 1;
	if (name == "pearl ring")
{
     tell_object(me,
@RING
���Ů�ӹ������ָ�Թ�һ������������һ�ڵ�����������Ǽٻ��� !! 
�㻨�˶���ԩ��Ǯ��ģ� �����ѽ�ָ������һ������Ҳ����һ�ۡ�
RING
	);
        command("drop "+name);
        return 1;
}
     tell_object(me,
@MISSION
���Ů�ӹ�����Թ�һ������������ͻȻ������â��
���е��������������Ʒ�� !! �������úü������� ����
˵�����Ͳ��������ˡ�
MISSION
	);
		item->remove();
		this_player()->set_temp("give_pearl",1);
        return 1;
}

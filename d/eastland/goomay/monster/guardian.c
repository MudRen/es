
#include "../goomay.h"
#include <stats.h>
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Guardian", "�᳡����" );
        add ("id",({ "guardian"}));
        set_short( "�᳡����");
        set("unit","λ");
        set_long(
@C_LONG
����һ�����ļ�Ϊ���µ�����������������ϸϸ��Ƭ�����Ϸ���������͹⣬
��������������������������ȵ�������ʲ�ῴ����Ǯ�� ! ÿ�˻ƽ���ʮ�� !��
C_LONG
);
		set("no_attack",1);
        set ("gender", "male");
        set("exp_reward",61) ;
        set_natural_weapon(65 , 30 , 45) ;
        set_natural_armor( 80, 40 ) ;
        set ("race", "lizardman");
}

void init()
{
        add_action( "pay_me", "pay");
}

int pay_me(string arg)
{
        string who, type;
        int num;
	object obj;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail("��˭������Ǯ��\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
         tell_room( environment(), 
          "�����е�: �������𣿲��Ǹ���˵Ҫ�����\n",
          this_object() );
                return 1;
	}
       if( !this_player()->debit(type, num) ) return notify_fail( 
           "��û��������ҡ�\n");

        if( num < 50 ) {
         tell_room( environment(), 
          "�����е�: ����ƭ������Ǯ���� ! û�� !!\n" ,
          this_object() );
                return 1;
	}

	obj = this_player();
	if (num>=50) 
	{
        tell_room( environment(), 
         "������"+obj->query("c_name")+"���ͷ˵��: �� !! ��ȥ�� ! ���Ұ����ƽ��䶷��᳡��\n"
		, ({obj}) );
        tell_object( obj, 
         "����������˵��: �� ! ��ȥ�� !! ���Һܴ�³�İ����ƽ��䶷��᳡��\n"
                );
      obj->move_player( Goomay"coliseum2", "SNEAK" );
        tell_room( Goomay"coliseum2", 
          obj->query("c_name") + "����ײײ���ܽ�����\n"
	,obj );

	return 1;
	}

}

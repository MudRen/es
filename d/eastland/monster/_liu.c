
#include <mudlib.h>
void create(object ob)
{
		if ( !ob ) return ;                                         
        ob->set_level(5);
        ob->set_name( "liu", "������" );
        ob->add ("id", ({ "liu",}) );
        ob->set_short( "������" );
        ob->set_long(@C_LONG
    ���Ǹ���Լ��ʮ�������ˣ�������ɫ���ţ���������ʲ���Ƶġ�
����һ˫��ʵ������������һ���Ǹ��Ʒ����֡�
C_LONG
        );
        ob->set( "gender", "male" );

        ob->set_skill( "longblade", 25 );

        ob->set_natural_armor(35,10);
		ob->set_natural_weapon(18,2,7);
		ob->set("special_defence", ([
			"all" : 33 ]) );
					
		ob->wield_weapon("/d/eastland/obj/seven");
}

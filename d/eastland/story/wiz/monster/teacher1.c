#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "teacher", "˽�ӽ�ʦ" );
	set_short( "˽�ӽ�ʦ" );
	set_long(@C_LONG
һλ���ڿ���������������ʦ��������΢�֣�һ��С�۾�������Сñ�ӣ��ڡ���
�ɣ������൱���ࡣ
C_LONG
        );
	set( "gender", "male" );
        set( "unit","λ");
        set_natural_armor(60,0); 
        set_natural_weapon( 17,9,20 );
        set( "inquiry", ([
             "special_things":"@@ask_things",
        ]) );
}
void ask_things(object asker)
{
tell_room(environment(),@LONG
                            
˽����ʦ˵�����ر�Ķ���������ƽ�������ر����ǿ�ˮ��������(crystal_glass)
             ��������ĳ��棬�����ںڰ������Ź�â��
                                      ����
LONG
     );
}

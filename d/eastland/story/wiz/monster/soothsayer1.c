#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "soothsayer", "������" );
	set_short( "������" );
	set_long(@C_LONG
һλ�׷��ԲԵ���̫�ţ����������۾�ע������ǰ��ˮ�����������鼫�����С�   
C_LONG
        );
	set( "gender", "female" );
        set( "unit","λ");
        set( "wealth/silver",100);
        set_natural_armor(65,0); 
        set_natural_weapon( 23,9,23 );
        set( "inquiry", ([
            "crystal_glass":"@@ask_crystal",
        ]) );
}
void ask_crystal(object asker)
{
    tell_room(environment(),@LONG
                            
������ŭ����С����û�����ҵ�ˮ����������
                                      ����
LONG
   );
}

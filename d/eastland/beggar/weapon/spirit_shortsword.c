#include "../dony.h"

inherit WEAPON;

void create()
{
	set_name( "spirit shortsword", "������" );
	add( "id", ({ "shortsword","sword","spirit" }) );
	set_short( "������" );
	set_long(@C_LONG
�����ɾ�����������ɵ�һ�ڱ�������Ȼ����һ�Ѿ�����˫���������,������Ҫ
�����������İ���,�����ܴ�����Ī��ĺô���
C_LONG	
	);
	set( "unit", "��" );
	set( "weight", 0 );
	setup_weapon("shortblade",25,24,27);
        set("prevent_drop",1);
        set( "prevent_drop", 1 );
        set( "prevent_get", 1 );
        call_out( "vanish_out",3600,this_object());
}
void vanish_out(object ob)
{
        ob->unwield(1);
        ob->remove(1);
        return ;
}

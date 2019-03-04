#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire dragon whip", "������" );
	add( "id", ({ "whip" }) );
	set_short(  "������" );
	set_long(
	  "����һ�����ɫ�����ޣ�ƽ���ǹ����ҵ��������ʱ�������ԵУ�\n"+
	  "������һ�����ص�ħ����\n"
	);
	set( "unit", "��" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 10,20);
	set( "value", ({ 340, "silver" }) );
//        set( "hit_func", "special_hit" );
        set_verbs(({"%s˦��%s","%s����%s","%s����%s"}));

}

int special_hit(object victim)
{	
	object holder;
	holder=environment(this_object());
        if( random(holder->query_perm_stat("pie")+
		   holder->query_perm_stat("int"))<20) return 0;
        if( victim->query("stop_attack") ) return 0;

        tell_object( victim,
          "\n�����޿��ٵ���������Ӱ����һ��������������!!\n\n");
        tell_object( holder, 
          "\n�㼱�ٵ����������ޣ���Ӱ����һ�������������ȥ !!\n\n");
        tell_room( environment(holder),
          "\n�����޿��ٵ���������Ӱ����һֻ������" + victim->query("c_name") +"��ȥ !!\n\n"
	, ({ victim, holder }));
        victim->receive_special_damage("fire",8+random(10));
        return 1;

}

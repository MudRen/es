#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "jade dagger", "���ذ��" );
	add( "id", ({ "dagger" }) );
	set_short( "���ذ��" );
	set_long(
		"һ�Ѿ��µ����ذ�ף����ĵ������ô����ĥ�ɵģ��������ϵȵĺ�̴ľ\n"
		"�Ƴɡ���Ȼ���ذ�׿��������Ǻܷ��������ǵ�������ָ�������ĵ���ʱ\n"
		"����ĵ����и����㣬���ذ��ɱ��������....��\n"
	);
	set( "unit", "��" );
	set( "type", "dagger" );
	set( "weapon_class", 43 );
	set( "min_damage", 25 );
	set( "max_damage", 40 );
	set( "extra_skills",(["anatomlogy":5,"bandage":10]) ) ;
	set( "weight", 30 );
	set( "value", ({ 500, "gold" }) );
	set( "no_sale", 1 );
    set( "hit_func","light_damage" );
}

int light_damage(object victim,int damage)
{
	object holder;
   	int pie,kar,vpie,vkar;
	int degree;
        int sp;
        
   	if( !victim ) return 0;
   	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   	pie = (int)holder->query_stat("piety");
   	kar = (int)holder->query_stat("kar");
   	vpie = (int)victim->query_stat("piety");
   	vkar = (int)victim->query_stat("kar");
   	if (userp(holder)) {
	   	if (pie>vpie) pie = vpie;
	   	if (kar>vkar) kar = vkar;
   	}
   	if (random(pie+kar) < 2* random(vpie+vkar)) return 0;
   	if (userp(holder)) {
		sp = holder->query("spell_points");
		if (! sp || sp < 3) return 0;
		holder->set("spell_points", sp -3 );
	}
	tell_object( holder,"������ذ�׷���һ��ѣĿ�Ĺ�â, ����"+
	             victim->query("c_name")+"���۾���\n\n");
	tell_object( victim,holder->query("c_name")+
	             "�����ذ�׷���һ��ѣĿ�Ĺ�â, �������۾���\n\n");
	tell_object( victim,"��е��۾�һ����ʹ....�㿴���������ˡ�\n");
	tell_room( environment(holder),
	             holder->query("c_name")+"�����ذ�׷���һ��ѣĿ�Ĺ�â, ����"+
	             victim->query("c_name")+"���۾���\n\n",({holder,victim})
	            );
    degree=victim->query("blind")+1;
    if (degree>10) degree=10;
    victim->set("blind",degree);
	return 0 ;
}

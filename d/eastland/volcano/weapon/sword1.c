#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Dragon sword", "����" );
	add( "id", ({ "sword", "dragon sword" }) );
	set_short( "����" );
	set_long(
   "����һ���ú��׾������������ٵ�����Ѫ������֮�����Ǿ������ı�ʤ������\n" );
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 200 );
	set( "weapon_class", 45 );
	set( "min_damage", 30 );
	set( "max_damage", 50 );
        set( "special_damage", 40 );
	set( "value", ({ 500, "gold" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
        int my_pie,vic_pie,sp,dam;

	owner = environment();
        sp=owner->query("spell_points");
        if ( sp < 6 ) return 0;
        my_pie = (int)owner->query_stat("pie");
        vic_pie =(int)victim->query_stat("pie");
        if( random(my_pie*3) < vic_pie*2 ) return 0;
        if( !(dam = (int)query("special_damage")) ) return 0;
        owner->set("spell_points",sp-6);
        if ((int)owner->query_skill("longblade")<95) {
          tell_object(owner,
              "\n����ǿ�Ӷ������������óɵı�����ʴ���Լ�.\n\n");
          tell_room(environment(owner),
              "\n"+owner->query("c_name")+"�������������óɵı�����ʴ���Լ�
.\n\n",
              owner );
          owner->receive_special_damage("cold",dam);
          return dam;
        }

          tell_object(owner,
           "\n��������ӳ�һ�����⣬�ó�һ����������ĵ�����ȥ��\n\n");
          tell_room(environment(owner),
            "\n"+owner->query("c_name")+"�������ӳ�һ�����⣬�ó�һ�������������ȥ��\n\n" 
            , owner );
           victim->receive_special_damage("cold",dam);
           return dam; 
}

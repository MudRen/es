#include "../zeus.h"
inherit WEAPON;
void create()
{
       set_name("magic dagger","ħ��ذ��");
       add("id",({"magic","dagger",}) );
       set_short("ħ��ذ��");
       set_long(@LONG
����һ����ħ�������������������ذ�ף�ͨ�巢������ɫ�����⣬
�ƺ�������δ֪��ħ��������
LONG
);
	
	set( "unit", "��" );
 	set( "weapon_class", 30 );
        set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 90 );
	set( "no_sale",1);
	set( "value", ({ 100 , "silver" }) );
//    set("hit_func","damage");
    set("wield_func","chname");
    set("unwield_func","rename");
    set("master","");
}
int chname()
{ 
	string who;
	object hero;
  hero=environment(this_object()); 
  if ( (string)hero->query("name") == (string)query("master") ) {
        set( "weapon_class", 42 );
	set( "min_damage", 25 );
        set( "max_damage", 39 );
  who="Ӣ��"+this_player()->query("c_name")+"��ذ��";
   set_name("magic dagger",who);
   set_short(who);
   tell_object(hero,"\nħ��ذ��ͻȻ��â��ʢ����ذ����ͻȻ���ֳ�������� !!\n");
   }
}
int rename()
{ set_name("magic dagger","ħ��ذ��");
  set_short("magic dagger","ħ��ذ��");
 	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
  } 


int damage(object victim)
{
    object holder;
    int dam,min,max;
    holder=environment(this_object());
    if (!holder->query_temp("get_magnetite")) return 0;  
    if ( !victim ) return 0;
    if( !(holder) || !living(holder) ) return 0;
      max=(int)holder->query_stat("str");
      min=(int)holder->query_stat("kar");
        if ( random(140-min) <20) {
		victim->receive_damage(10+random(max) );
		victim->set("last_attacker", holder );
		tell_object( holder,
			"\n���ذ�׷���һ����ãã������Ʈ����ˣ���������գ�����һ���׹�����������࣮\n\n");
		tell_room(environment(holder),
		"\n�㷢��"+(string)this_object()->query("c_name")+"����һ������ѵ��˾��ϰ���У��׹�ͻȻһ����\n\n",
		holder );
        }
      return 0;  
}

#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "hostress", "Ů����");
        set_short("Ů����" );
	set_long(@C_LONG
Ů����ԼĪ��ʮ������ͣ�ȴ����������֮ò���������˿�˵����������һ˫��
�ڶ�ʮ����ǰ��Ů������λ�䶯���־�����̵���������˼��ٳ�ս�ۣ�ȴ��δ
����ܹ������ü���Ϊһ������֮�С�Ů�����Դ���������������һʱ����Ϊ����
�����ȴ�ĸ���Ը����������˫˫�������ӵ����һ�����˼�Ϊ���죬ȴ�����
������������
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 70 , 30 );
	set_natural_weapon( 24 , 8 , 6);
	set("max_hp",700);
	set("hit_points",700);
        set("max_fp",500);
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",80 );
	set_skill( "longblade",70);
	set("spouse","host");
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 45,"none":30 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":60,"weakest":50]) );
	set("couple",1);
        equip_armor(LARMOR"moon_ring");
        equip_armor(LARMOR"moon_amulet");
        wield_weapon(LWEAPON"red_sle");                                              
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                "third":"@@ask_third",
                         
        ]) );
        set("scholar_gonfu/couples_sword",30);
        set("scholar_gonfu/han",30);
} 
void ask_third(object asker)
{
write(@C_LONG
Ů���˵������๫Ҫ��������ร��Ǻðɣ��Ҹ���һ�����������Ƥ���ϻ���
���������������������Իظ�������ò��ϣ����Ϊ������취��
C_LONG
      );
}
int accept_item(object me, object item)
{
   string pname,name;
   pname=me->query("name");
   name=item->query("name");
   if( name!="red fruit" ) {
      command("give "+name+" to "+pname);
      tell_object(me,"Ů���˵����ף���������������ʲ�ᰡ��\n");
      return 1;
   }
   if( me->query_temp("third") ) {
      tell_object(me,@C_LONG
Ů����˵����лл�����Ѿ��������ˡ�      
C_LONG
   );   
      command("give "+name+" to "+pname);
      return 1;
   }
   tell_object(me,@C_LONG
Ů���˳�����������������˲�������˺ü�ʮ�ꡣ�ۣ��ȡ�ŷ�ס��������㣡

Ů���˸м�������˵лл ^_^

C_LONG
    );     
    item->remove();
    me->set_temp("third",1);
    return 1;
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}

int my_attack()
{ 
   object *couples,victim;
   int i;

   if( !victim =query_attacker() ) return 0;
   
   if( query("force_points") < 50 ) set("force_points",500);
                        
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), sprintf(
          "%sŭ��:��������������۸���,�����µ���ȥ��!!\n",couples[i]->query("c_name"))
          ,couples[i]);
      couples[i]->kill_ob(victim);
   }
   if ( !present("host",environment(this_object())) ) {
        set("attack_skill","scholar/han");                                    
        delete_temp("extra_db");
   }
   else set("attack_skill","scholar/couples_sword");
   return 0;
}

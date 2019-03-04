#include <../legend.h>

inherit MONSTER;
void create ()
{
        ::create();
        set_level(19);
        set_name( "yellow daoist", "éɽ��ʿ ���컯" );
        add("id", ({"daoist"}) );
        set_short( "éɽ��ʿ ���컯");
        set_long(@C_LONG
����ǰ������λ�����������������ֲ��ޱ߷���éɽ��ʿ�����ǣ���ɱ�С����
����Ϊ�����ֽ�éɽ�ɵ���ʮ�˴��������ˣ������书�ߣ�������������ޱȣ���
����ħ��������Ӯ�ý�����ʿ�İ��ء����컯�����˵�˴�����ħ��ֳ��֣�����
�鿴һ�������컯���ˣ���ü����������������ʲ���鷳��
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
        set( "alignment", 400 );
        set_natural_armor( 35, 48 );
	set_natural_weapon( 53,12,36);
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 28 );
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 80 );
        set_skill( "axe",75);
	set( "max_fp",500);
	set( "force_points",500);
        set( "hit_points", 900 );
        set( "max_hp", 1000000 );
        set("conditions/_heal_hp",({ 10000 , 1 }) ) ;
        set( "special_defense", ([ "all": 50,"none":40,
                "monk":40,"scholar":20]) );
        set( "stun_difficulty",50);
	wield_weapon( LWEAPON"mahogany_axe.c" );
	equip_armor( LARMOR"daoist_cloth" );
        set( "chat_chance", 10 );
        set( "att_chat_output", ({
                "���컯�������������������� !!����\n",
	}) );
        set( "inquiry", ([
             "trouble":"@@ask_trouble",
             "������":"@@ask_ball",
             "��֧��":"@@ask_mob",
        ]) );
        set( "tactic_func", "my_tactic" );
}
void ask_trouble(object asker)
{
write(@C_LONG
���컯̾������������˵�˴����Ϲ����ޡ���֧���������շ�������ȴ����������
����������  ���˼�����ˣ�������ʧ��һ�Ű���������ý��������项��ϣ��
���������������������һ���������ʰ����֧����
C_LONG
      );
}           
void ask_ball(object asker)
{
write(@C_LONG
���컯�������ʡ������项?
          Ŷ,����һ����ɫ��ԭ����ֻ���ں��� ( roll sea-ball ) �Ϳ���
          �ѡ���֧����������������С�ģ���Ϊ....
C_LONG
      );          
}
void ask_mob(object asker)
{
write(@C_LONG
���컯��������֧�������Ϲ����ޣ������и���ı��ܣ��ó�������һϢʱ��
����������  ��������ס�����Ʒ�����
C_LONG
     );
}
int my_tactic()
{
   int i,num;
   object victim,env,*all,help;
   
   if ( !victim=query_attacker() ) return 0;
   if ( random(10)>2 ) return 0;
   env=environment(this_object());
   all=all_inventory(env);
   num=0;
   for (i=0;i<sizeof(all);i++)         
     if ( all[i]->query("paperman") ) num+=1; 
   if ( num>2 ) return 0;  
   tell_room(env,"\n���컯��æ�ӻ����ͳ����䣬�����һ������Ϊһ���׶�ֽ�ˣ�\n\n");    
   for (i=0;i<(3-num);i++) {
      help=new(LMONSTER"paperman");
      help->move(env);
   }
   return 0;        
}
void die()
{
   int i;
   object env,*all;
   env=environment(this_object());
   all=all_inventory(env);
   for (i=0;i<sizeof(all);i++)
     if ( all[i]->query("paperman") ) all[i]->remove();
   ::die();
}
#include <mudlib.h>
#include <daemons.h>
inherit WEAPON;

void create()
{
    set_name("Rainbow ruler","�߲�����");
    add("id", ({ "ruler" }) );
    set_short("�߲�����");
    set_long(@C_LONG
һ�������Ƴɲ������߳��ĳߣ�����񹤾��£�������ʯ�鱦����ʱ������ú��
�������ޱȡ�
C_LONG
    );
    set( "unit", "��" );
    setup_weapon("thrusting", 45,30,45);
    set( "weight",200);
    set( "value", ({ 8000, "silver" }) );
    set("hit_func","special_attect");
    set_c_verbs( ({ 
        "��ִ%s����˦��%s",
        "��%s��Ȼ������ɳ���ֱֱ����%s",
        "��ն���˫�ֺ�ִ%s������%s�ݺ�����",
        "���е�%sͻȻ�䳤��һ�Ǻ�ɨǧ��֮�ƹ���%s"
    }) );
    set("extra_stats",(["dex":-5]));
}

int special_attect(object victim,int damage)
{
   object holder;
   string hname,vname;
   int my_str,vic_kar,dam,degree,hour;

   if( !victim ) return 0;

   if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   
   if( holder->query("spell_points")< 4) return 0;
   my_str=holder->query_stat("str");
   vic_kar=victim->query_stat("kar");
   vic_kar=vic_kar<5?5:vic_kar;
   degree=3*my_str-2*vic_kar+10;
   if( random(degree)<vic_kar ) return 0;
   hname=holder->query("c_name");
   vname=victim->query("c_name");
   victim->set("last_attacker", holder );
   if ( !holder->query("npc") )
      holder->add("spell_points",-4);
   sscanf(WEATHER_D->query_game_time(),"%d",hour);
   if ( ( hour > 18 ) || ( hour < 6 ) ) {
      dam=40;
      tell_object(holder,sprintf(
         "�����е���������ҹ������٣���%s������һƬ��ɫ�����â�\n\n\n",
         vname));
      tell_object(victim,sprintf(
         "\n%s���е���������ҹ������٣�����������һƬ��ɫ�����â�\n\n",
         hname));
      tell_room(environment(holder),sprintf(                        
         "%s���е���������ҹ������٣�%s������һƬ��ɫ�����â�\n",
         hname,vname),({holder,victim}));     
      victim->receive_special_damage( "mental",dam );
   }
   else {
      dam=30;
      tell_object(holder,sprintf(
         "�����е����߷���һ��ʥ��Ĺ�â����ɢ��%s���ĵ�а��У�\n\n\n",
         vname));
      tell_object(victim,sprintf(
         "\n%s���е����߷���һ��ʥ��Ĺ�â����ɢ�������ĵ�а��У�\n\n",
         hname));
      tell_room(environment(holder),sprintf(
         "%s���е����߷���һ��ʥ��Ĺ�â��������%s�����࣡\n",
         hname,vname),({holder,victim})); 
         victim->add("alignment",50);
         victim->receive_special_damage( "divine",dam );
   }
   return dam+damage;
}

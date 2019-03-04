#include "../../story.h"
#include "../../magic.c"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(19);
	set_name( "King of wizard", "������" );
	add ("id", ({ "king","wizard"}) );
	set_short( "���� ������");
	set_long(@CLONG
����ǰ��������һλ���ʱ�������޳���Ϳ��Ʋ��ܴ���������������ϡ�����
������ٳ����������ˣ�������һ�����ӣ��������ǵ��ɢ�����������⣬����׹
�����������һ�����ľͻ�е�����ƽ�͡����޳���Ӣ�����ǻۣ��������ԣ�ߪ
���˲ţ����ĵ�ʶ�������൱���������������������������Ī������ƽ��������
ս�����аܼ����������Ǽ�����ͳ̶ȣ��������λ���������ĺû�飬����λ��
���𾴵ĺ���˾����֪�����ģ��㷢������������ɫ���ƺ�����һЩ���� (trou
ble)�� 
CLONG
	);
	set("flute",1);
	set("race","human");
        set("race","��ʦ");
	set("gender","male");
	set_perm_stat("str", 30 );
        set_perm_stat("dex", 30 );
        set_perm_stat("kar", 30 );
        set_perm_stat("int", 30 );
	set( "alignment", 5000 );
	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
        set( "max_fp",500);
	set_natural_weapon( 25, 30, 45 );
	set_natural_armor( 86, 55 );
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":80,"ganglion":80,"weakest":80 ]) );
        set("wealth/gold",500);
        set("stun_difficulty",100);
        set("conditions/_heal_hp",({ 3 , 1 }) ) ;
        set_skill("parry",100);
        set_skill("block",100);
        set_skill("jousting",100);
        set_skill("two-weapon",100);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"wiz_lance");
        equip_armor(SWARM"wiz_shield3");
        equip_armor(SWARM"wiz_ring2");
        equip_armor(SWARM"wiz_cloak1");
        equip_armor(SWARM"wiz_helmet1");
        set("special_defense",(["all":50,"none":40,"monk":40]));
        set("inquiry",([
              "great_bag":"@@ask_bag",
              "fly_flute":"@@ask_flute",
                "trouble":"@@ask_trouble",
        ]) );
}
int accept_item(object player, object item)
{
      string iname,pname,pcname;
      
      if ( !item->query("spiritball") ) {
         tell_room(environment(),"������˵���������ⶫ��������ֲ����������ġ�\n");
         item->move(environment());
         return 1;      
      }
//    if ((int)player->query_quest_level("wizking")>0 ) {
      if ((int)player->query("quests/wizking")>0 ) {
         write("������˵����лл���ٴΰ�æ��\n");
         return 1;
      } 
      iname=item->query("master");
      if (!(pname=player->query("org_name"))) pname=player->query("name");
      pcname=player->query("c_name");
      if ( iname!=pname ) {
         tell_room(environment(),sprintf(
           "����������%s������ԭ��������͵�ģ�����ȥ���ɣ���\n",pcname),player);
         tell_object(player,"\n���������㺰����ԭ������͵�ģ�����ȥ����\n\n"); 
         kill_ob(player);
         item->remove();
         return 1;
      }
      write(@LONG
      
 ������˵����лл������һ������顣

 [ ��������ĵؽ���������������ѣ��������������ʹ͵� 15000 ��ľ���ֵ]    

LONG
      );
      // player->finish_quest("wizking",1);
      player->set("quests/wizking",1);
      player->gain_experience(15000);
      item->remove();
      return 1;
}
void ask_trouble(object asker)
{
  write(@LONG
������˵���������Ұ����֮����������(spirit_ball)��Ū���ˣ����ܰ�����
            ��������ϸ������ȥ�ʻ���ʦ���ˣ�������û����������ۡ�
              
LONG
  );
}
void ask_flute(object asker)
{
   object flute;
   if( !asker->query_temp("flute_asked",1) ) {
     write("������˵�����ߣ��޳�С�����㵽���Ǵ����������������֮�ѡ��ģ�\n");
     return ;
   }
   write("������˵����Ŷ��ԭ����������˵Ҫ���ûء�����֮�ѡ���ร�\n");
   if( !query("flute") ) {
     write("������̾�������Ѿ��ѵ��Ӹ������ˣ����ƺ�����̫���ˡ�\n");   
     return ;
   }
   flute=new(SITEM"flute1");
   if (flute->move(asker)!=0) {
     write("������˵�������̫���ˣ���һЩ�������ɡ�\n");
     flute->remove();
     return ;
   }
   set("flute",0);
   flute->move(asker);
   write(@LONG
������˵�����ðɣ��Ҿ͸���ɡ�
����������һ��������֮�ѡ���
������������������֮�ѡ�����ҵ��û����Դ(flute_energy)�ˣ�����������취�ɡ�
LONG
   );
   tell_room(environment(),"������¶���ƻ���΢Ц��\n");
   asker->delete_temp("flute_asked");
   call_out("back",300);
   return ;
}
void back()
{
   set("flute",1);
}
int get_bag(string name,string *names)
{ 
    int i,max;
    max=sizeof(names);
    for (i=0;i<max;i++)
      if ( name==names[i] ) return 1;
      else return 0; 
}        
void ask_bag(object asker)
{
    object env,bag,*get,ball;
    string name,*names;
    if ( !asker->query("quests/wizking") ) {
       write("������˵�����ţ��޵״����ҳ��ڵ��ز���\n");
       return ;
    }
    if (!(name=asker->query("org_name"))) name=asker->query("name");
    env=environment(this_object());
    names=env->query("bag_asked");
    if (!get_bag(name,names)){
       write("\n������˵��������������һ�������ķ��ϣ��Ҿ͸���һ���޵״���\n\n");
       env->add("bag_asked",({name}));     
       tell_object(asker,@LONG

ֻ�����������־�����ղ���������....

�ţ���Ȼ�ӿ��е���һ���޵״�������

������˵�����ţ��ú��ӣ������͸���ģ�^_^��

LONG
       );
       bag=new(SWITEM"bag1");
       bag->set( "max_load", 1500);
       bag->set( "weight_apply", 25 );
       bag->set("no_sale",1);
       bag->move(env);      
       return ;
    }       
    tell_object(asker,"�����������ɵ��۹⿴���㣺�ף��㲻���Ѿ�����Ҫ��һ���޵״�����\n");
    return ;
}
void init()
{
   ::init();
   add_action("do_embattle","embattle");
   add_action("do_demand","demand");
}
int can_help( object ob )
{
   if ( !living(ob) ) return 0;
   if ( ob->query("bodyguard") ) return 1;
   return 0;
}

int stop_attack()
{
    int i,max;
    object *tmp, env, *atk;
        
    env=environment();
    atk=filter_array(all_inventory(env),"can_help",this_object());
    max=sizeof(atk);
    for ( i=0;i<max;i++ ) {
        tell_room( env,sprintf(
           "%s�嵽��������ǰ�����Ҵ����������д̿ͣ���ҿ챣�������İ�ȫ��\n"
           ,atk[i]->query("c_name")) );
        tmp = query_temp( "protectors" );
        if( !tmp || member_array( atk[i], tmp )==-1 ) {
           add_temp( "protectors", ({ atk[i] }) );
           atk[i]->add_temp( "protectees", ({ this_object() }) );
        }
        atk[i]->kill_ob(this_player());
    }
    return 0;
}
int do_embattle(string arg)
{
   object player;
   player=this_player();
   if ( player->query("class")!="scholar" ) return 0; 
   write("������������������󷨵���ͼ����Ǹ���һ�����ص�ʹ����\n");
   player->add("hit_points",-20);
   player->add("spell_points",-40);
   return 1;
}
int do_demand(string arg)
{
   object player;
   player=this_player();
   if ( player->query("class")!="scholar" ) return 0;
   write("�������������л��ľ���һ�ڳ�����ȥ��\n");
   player->add("spell_points",-40);
   add("hit_points",200);
   return 1;
}
int my_tactic()
{
    int i;
    object victim,env;
    string name;
    
    if ( !victim=query_attacker() ) return 0;
    env = environment( this_object() );
    name=victim->query("c_name");
    switch(random(60)){
    case 0..3 : 
        tell_object(victim,set_color(
           "\n\n��⣡�������ƺ�����������������㣡\n\n","HIW"));
        tell_room(env,sprintf(
           "������������%s���������㣡\n",name),victim);
        victim->set("hit_points",victim->query("hit_points")/3);
        return 1;
    case 4..9:    
        tell_object(victim,
        "\n���������еİ���ǹ����һ�����ߣ�������������ʮ��ǹ��ǹǹ������\n\n");
        tell_room(env,sprintf("����������%s���̺ü�ǹ!\n",name),victim);
        victim->receive_damage(70+random(10));
        report(this_object(),victim);
        return 1;
    default :
        return 0;
    }   
}

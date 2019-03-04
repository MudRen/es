#include "../almuhara.h"
 
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "The archmaster", "���ʦ" );
        add ("id", ({ "daemon", "master","archmaster" }) );
        set_short( "���ʦ  Т��");
        set("unit","λ");
        set("exp_reward",40000) ;           
        set("alignment",3100);
        set("wealth/gold",500);
        set_long(
            "���ʦ  Т����һλ��Ŀ���Ƶ��ˣ���������Լ����ʮ���꣬������֪����\n"
            "���Բ�ֻ�����͡���˵��������������ħ���ս���Ҵ���ˣ����������\n"
            "����½���ӡ���Ϊ�ܻʵ۵����٣�Т����˶��������Ĺ�ʦ��������������\n"
            "ɽ  ����ʦ�����£���Ϊ��ʦ�ĵ�����ӣ�������������Ŷݼס�������ľ\n"
            "֮ѧ���ټ�����������֪ʶ��������ʹ����Ϊ���˾��صĴ��ʦ��\n"
        );
        set_perm_stat("str", 25);        
        set_perm_stat("int", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar",30);
        set_natural_weapon( 50, 20, 30 );
        set_natural_armor( 100, 50 );
        set_skill("dodge",100);
        
        set ("gender", "male");
        set ("race", "daemon");
        set("max_hp",1500);
        set("hit_points",1500);
        set("time_to_heal",2);
        set("max_sp",2000);
        set("spell_points",2000);
        set( "tactic_func", "my_tactic" ); 
        set("aim_difficulty",(["critical":60,"weakest":60,
                               "vascular":30,"ganglion":60 ])) ;
        set("stun_difficulty/ma",20) ;
        set("unbleeding",1);
        set("special_defense",(["all":70,"none":50,"monk":60,"scholar":60]));
//        set("moving",1);
//        set("speed",30);
//        set("patrol",({"south","sotuh","north","north"}) );
        set( "chat_chance", 10);
        set( "chat_output", ({
        	"���ʦ����ؿ����㣬�ݷ�Ҫ�������������\n",
        	"���ʦ����������������\n" }) );
	set( "att_chat_output", ({
		"���ʦҡҡͷ˵����Ϊʲ��������˲���ϧ�Լ��������أ�\n",
		}) );
        wield_weapon(WEAPONS"/ling");
        equip_armor(ARMORS"/master_hat"); 
        equip_armor(ARMORS"/master_boots");
        equip_armor(ARMORS"/master_robe");
        equip_armor(ARMORS"/master_amulet");
        equip_armor(ARMORS"/master_ring");        
        equip_armor(ARMORS"/shield1");
        set( "inquiry", ([
"almuhara" : ({"��������õ����ѡ�\n" }),
"wiwi" : ({"�����������ð���\n" }),
"blackjack" : ({"������������һ������ͷ��\n" }),
"monmonpig" : ({"��˵����������һ��...... :~~~~    ��Ҫpk !!\n"}),
"kenwahl" : ({"һ������ʦ����Ҫ����...\n"}),
"����" : ({"���������Ǻ��ֱ����������\��\........:~~~ \n" }),
"jade" : ({"���壿ʲ���������壿�ɷ���ҿ�����\n" }),
"seal" : "@@ask_seal",
"tomb" : ({"��������� ?\n" }) ]) );
}
 
void ask_seal(object who)
{
	if ( who->query("quest/sky_guilt") ) {
		tell_object( who, 
		"���ʦ˵�����ǳ�лл��İ�æ��\n" );
		return; }
	if ( who->query("sky_guilt") ) {
		tell_object( who,
		"���ʦ˵��������!!\n" );
		return; }
        if ( (int)who->query_level() < 17 ) {
                tell_object( who,
                "���ʦ˵��������ϧ�Լ������������������������˵�ɡ�\n" );
                return; }
        if ( who->query("guilt_jade") ) {
                tell_object( who,
                "���ʦ̾��һ������˵������ �Ƿ�ӡ�����������˼����� --������ġ�\n"
                "������ǰ���Ͻ��˽����뽣ڣ���Ҿ�������ò��ף�ֻ���ҵ�ʱû�����ɲ�\n"
                "�ɣ���������ȡ�����������Ρ���Ȼ�������ƽ�����ס���������������֮\n"
                "����\��\���������������շ���ϣ���������ҳ������ޣ��������������ҡ�\n"
                "�����һ�ž�ת�𵤣�Ӧ�ö�����Щ��������\n\n" );
                who->delete("sky_guilt");
                new(ITEM"/great_pill")->move(who);
                call_out("give_jade",6,who);
                return; }
        tell_object( who,
                "���ʦ̾��һ������˵������ �Ƿ�ӡ�����������˼����� --������ġ�\n"
		"������ǰ���Ͻ��˽����뽣ڣ���Ҿ�������ò��ף�ֻ���ҵ�ʱû�����ɲ�\n"
		"�ɣ���������ȡ�����������Ρ���Ȼ�������ƽ�����ס���������������֮\n"
		"����\��\���������������շ���ϣ���������ҳ������ޣ��������������ҡ���\n"
		"����һ�ž�ת�𵤣�Ӧ�ö�����Щ��������\n" );
                who->set("sky_guilt", 1);
                new(ITEM"/great_pill")->move(who);
                return;
}
 
void give_jade(object who)
{
        tell_object( who ,
                "���ʦ˵��������...�������...�ϻ�Ū�õ���аʥ����������а����ԭ\n"
                "����������У�����Ϊ�����аʥ�񿪹⣬�����������������...\n\n"
                "���ʦ����һЩ����......\n\n"
                "���ʦͻȻץס����֣����е���ʦ����Ȼ���㻮������������һ�£�\n\n"
                "����������÷ǳ�׼ȷ��������ȥ��Сָ��һСƬƤ����������Ѫ��Ȼ����\n"
                "������....\n\n" );
        who->set_temp("block_command",1);
        tell_object( who,
                "���ʦ�������ٶȣ�����ֹѪ�����������Ѫ����аʥ���ϻ�����Щ�㿴\n"
                "�����ķ��š�\n\n" );
        call_out("tellmethod",12,who);
        return;
}
 
void tellmethod(object who)
{
        command("sweat");
        tell_object( who ,
                "���ʦ����˵�������������ʱ������аʥ��(throw)��������ܻ���\n"
                "���������������Ȼ��������ʤ��Ҳ�������ߡ�ף�㿭�����ǵð�����\n"
                "��������...\n\n" );
                new(ITEM"/holy_jade")->move(who);
                who->delete_temp("block_command");
                return;
}
 
void relay_message(string class1, string msg)
{
     string who,aa,str ,str1,str2;
     object *ob,obj,*obj1;
     int i,j;
     
     ::relay_message(class1, msg);
     if( sscanf( msg, "%s(%s)���˹�����\n", aa , who )==2 ) 
       {
         who = lower_case(who);
         obj = find_player(who);
         ob = all_inventory(this_object());
                i = sizeof(ob);
         while(i--) {
                        if( ob[i]->query("equipped") || ob[i]->query("wielded") ) continue;
                      //  if( undefinedp(ob[i]->query("armor_class")) &&
                      //     undefinedp(ob[i]->query("defense_bonus")) )
                      //          continue;
                        ob[i]->remove();
                }
          obj1 = all_inventory(environment(this_object()));
          	j = sizeof(obj1);
          while(j--) {
     		if( present("sky guilt", obj1[j]) ) { 
		        obj = obj1[j];
        	   if( (int)obj->query_temp("GUILT") && 
		        (int)obj->query_quest_level("Sky_guilt") < 1 ) {
      	           obj->finish_quest( "Sky_guilt", 1 );
         		tell_object( obj, 
         		"���ʦע���������ϵġ� ���� ����һ���ӡ�\n"
         		"\n\n"
         		"���ʦ˵��������лл��İ�æ�������ϵĹ�Ȼ�������ڡ� ���� ���ϱ���\n"
         		"����һ�ž��з����ĺ챦ʯ������ȴ�����ˣ��ѹ�����������š��������\n"
 	       		"��Ԧ�����������һ��ǿű�ʯ�����������С���У���Ȼ���������˵�����\n"
 	       		"��ม�\n"
 	        	"\n"
 	        	"������ˡ�������񣬵õ� 20000 ����ֵ��\n");
 			obj->gain_experience(20000);
 			obj->delete_temp("GUILT");
 			return; 
	 		}
	 	}	
         } 
    }
}
int my_tactic()
{ 
    object victim,env;
    int i,j;
 
    env = environment(this_object());       
 
    if( !(victim = query_attacker()) ) return 0;
 
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2000);
    
    if( ((int)this_object()->query("hit_points") < 200) && random(10) > 7 ) {
	tell_room(env,
		"\n"+"�㿴�����ʦ�г�ˮ֮������������˿ڡ�\n",this_object() );    	
      	this_object()->add("hit_points", 200); 
      	return 1; }
    
    i = 30 - (int)victim->query_perm_stat("int") ;
    j = 30 - (int)victim->query_perm_stat("kar") ;
    
    if ( random(50) < i+j  )
       { 
          if(random(5) < 2) {
          	if ( (int)this_object()->query("hit_points") < 200 ) { 
          	tell_room( env, 
          		"\n"+"���ʦ���Լ����ܵ��Ĺ���ת��"+victim->query("c_name")+"���ϡ�\n",
          		({victim,this_object()}) );	
		tell_object( victim, 
			"\n"+"���ʦ���Լ����ܵ��Ĺ���ת�������ϡ�\n");          
		this_object()->receive_healing(60);
		victim->receive_damage(random(50));  
		return 1;
                	}
                else return 0;
                }
          else 
		tell_room( env, 
			"\n\n"+"���ʦ�󺰣��� ������������ ��!!\n"+"\n\n" 
			, this_object() );
		victim->receive_special_damage("electric",80);  
          return 1 ;
        }
    else 
          return 0 ;
 
}
void die()
{
  int i ;
  object scroll,killer,*player ;
 
  player = users() ;
  killer = query("last_attacker") ;
  scroll = new("/d/mage/tower/obj/ltn4_scroll") ;
  scroll->move(environment(this_object())) ;
 
  for(i=0;i<sizeof(player);i++)
    {
  tell_object(player[i],"\n�𶯵Ĵ�ش������ʦ Т��ͳ��ı�̾ : \n
  ������Ҳ����ս֮�ﰡ!!! \n");
     }
 
  ::die(1) ;
}
int accept_item(object who,object item )
{
    if( (item->query("sky_guilt_jade1")) )
      {
        who->set_temp("ask_jade",1);
        tell_object(who,@MSG
���ʦ��ϸ�����������......
���ʦ�������ý��߲�ʯ���߲�ʯ��������ͬʱ����ǿ�⣬�յ���Ŀѣ��ҡ��
 
���ʦ���������˷ܵĹ�â��
���ʦ����˵���������ҽ��ҵ������Ѱ�ҵ���аʥ���һ���ݣ��ϻ����Ѿ�����
��������������������һ���ͻ����ˣ������������Ƕ����鷳��ȥ������������һ
���������������������
MSG );
      }
    if( (item->query("sky_guilt_jade2")) )
      {
        if (who->query_temp("ask_jade")) {
        tell_object(who,@MSG
���ʦ��ϸ�����������......
 
���ʦ�����е��������������ϿڽӺϣ�һ��������Ĺ�ã�������з�����ʹ���
��һ��ů��......
 
���ʦ���΢Ц�ض���˵��лл...����һ����������ӡҲ����ν��....
MSG );
who->set("guilt_jade",1);
} else {
        tell_object(who,@MSG
���ʦ��ϸ�����������......
 
���ʦ����˵�����������������͵���ģ���Ҫˣ��......
MSG ); }
      }
item->remove();
tell_object(who,"лл��......\n");
return 0;
}
#include "../asterism.h"

inherit MONSTER;

int done ;

void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "Gnome Archelder Orion","�ؾ�����" );
        add ("id", ({ "gnome", "elder","archelder","orion" }) );
        set_short( "�ؾ�����ŷ��");
        set("unit","λ");
        set("exp_reward",65535) ;           // bcz this mob is more terrible
                                            // then Rashudi to Players .
        set("alignment",1000);
        set("wealth/gold",300);
        set_long(
            "�ؾ����Ͽ�˵������������µ�ʩ���ߡ��ؾ����ܲص�ħ���飬\n"
            "�ټ���������ľ���������ħ�����飬ʹ����Ϊ��ӽ���ʦ�ĳ��ˡ�\n"
            "�ؾ�����Ӧ�����ֹ۵����壬����ŷ�𰲵�����ȴ��������������\n"
            "�ƺ���������Щ�鷳��\n"
        );
        set_perm_stat("str", 30);
        set_perm_stat("int", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar", 30);
        set_natural_weapon( 40, 20, 35 );
        set_natural_armor( 60, 45 );
        set ("gender", "male");
        set ("race", "gnome");
        set("max_hp",2000);
        set("hit_points",2000);
        set("force_points",1000);
        set("conditions/_heal_hp",({ 2 , 1 }) ) ;
        set("max_sp",2700);
        set("spell_points",2700);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);        
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("elemental",100);
        set_skill("black-magic",100) ;
        set("guild_levels/elemental",60);
        set("guild_levels/black-magic",60);
        set("guild_levels/guild",60);
        set("magic_delay",2 ) ;
        set("spells/fireball",8 );
        set("spells/sleet",6);
        set( "tactic_func", "cast_help" ); 
        set("aim_difficulty",(["critical":100,"weakest":99,
                               "vascular":50,"ganglion":100 ])) ;
        set("stun_difficulty",42) ;
        set("unbleeding",1);
        set("inquiry",([ 
                         "�鷳"    : "@@quest1" ,
                         "trouble" : "@@quest1" ,
                         "�Ų��޻�": "@@quest1a",
                      ]) ) ;
        
        set("special_defense",(["all":80,"monk":80,"scholar":80,"none":80]));
        wield_weapon(WEAPONS"wand03");
        equip_armor(ARMORS"helmet03"); 
        equip_armor(ARMORS"boots03");
        equip_armor(ARMORS"robe02");
        equip_armor(ARMORS"cloak_g01");
        equip_armor(ARMORS"gloves02");
        equip_armor(ARMORS"amulet_g02");
        equip_armor(ARMORS"ring03");        
        set("hunt_list",({ }) ) ;
        set("warn",0);
        set("exit_block",0 ) ;    
        set("echo_asterism",1);
}

void reset()
{
    done = 0;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "������"+who->query("c_name")+"��Ц˵: �㻹�ҽ������Ҿͳ�ȫ�㣬����!\n"
    ,  ({ this_object(), who }) );
    tell_object( who,
      "����������Ц˵: �㻹�ҽ������Ҿͳ�ȫ�㣬����!\n"
    );
    set("warn",1) ;
    return 1;
}

int member_killer( string a, string *b )
{
    int i;
    if( !b ) return 0;
    for( i=0; i<sizeof(b); i++ )
      if( a == b[i] ) return 1;
    return 0;
}

int hunt_check( object archelder, object victim )
{
    int i;
    object *attackers;
    string *hunt_list;
    
    hunt_list = archelder->query("hunt_list");
    attackers = archelder->query_attackers();
    if(member_group( victim, attackers )) return 0;
    if((int)query("warn")==1) 
        {
           set("warn",0);
           return 0 ;
         }
    if( victim &&
        member_killer( (string)victim->query("name"), hunt_list ) ) {
      tell_room( environment(archelder), 
        "ŷ��Ц��˵: "+victim->query("c_name")+"��QUITֻ���ӱ���ʵ���ѣ�����!\n"
        , archelder 
      );
      kill_ob( victim );
      set("warn",0);
      return 1;
    }
    set("warn",0);
    return 0;
}

void relay_message(string class1, string msg)
{
     string who, clas ,str ,str1,str2;
     object obj,obj1,*fill;
     int ali;
     
     ::relay_message(class1, msg);
     if( sscanf( msg, "%s(%s)���˹�����\n",str,who )==2 ) 
       {
         who = lower_case(who);
         obj = present(find_player(who),environment(this_object()));
         clas = (string)obj->query("class");
         if(!obj) return ;
         
         set("aab",who) ;
         set("aac",str) ;
         if( hunt_check(this_object(), obj) ) return;
       
 //   This is the first quest of asterism city   
         
         if( done ) return ;
         if( !obj->query("quest/astr1")&&obj->query_temp("astr/quest1fin") )
           { tell_object( obj ,
                   "ŷ������������һ��������ص�Ц��Ц˵:\n"
                   "��֪���������ˡ��ǳ�лл��İ�æ,ϣ�����������Щ������\n"
                   "ŷ�𰲶����ſ�����,һ�������������ʱ������������ܡ�\n"
                   "                ��õ���ǧ�㾭��ֵ��\n"
                       ) ;
             obj->gain_experiance(5000) ;
             obj->set("quest/asterism1",1) ;
             obj->delete("astr") ;
             obj->delete_temp("astr") ;
             done = 1 ; 
            }
         return;
       }

}

int accept_item(object me,object item)
{
//   Avoid players fill the mob to decrease DEX .
         tell_room( environment(),
                  "ŷ�����ְ����õ���"+item->query("c_cap_name")+
                  "����ɷۡ�\n"
                  , this_object() ) ;
                            
         item->remove() ;           
         return 1 ;
}

int cast_help()
{ 
    object victim, monster, env;
    string victim_name, *hunt_list;
    int i,j,ran,vickar,vicint,ref;

    env = environment(this_object());       
    hunt_list = this_object()->query("hunt_list");

    if( !(victim = query_attacker()) ) return 0;
    victim->set_temp("once_k_archelder",1) ;    
    victim_name = (string)victim->query("name");

    if( !hunt_list )
      hunt_list = ({ victim_name });
    else if( !member_killer( victim_name, hunt_list ) )
      hunt_list += ({ victim_name });
    this_object()->set("hunt_list", hunt_list);

    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2700);
    
    vicint = victim->query_perm_stat("int") ;
    vickar = victim->query_perm_stat("kar") ;
    
    if(victim->query("npc"))victim->remove() ;

    i =30-vicint ;
    j =30-vickar ;
    
    if( i+j < 1 )  ref = 1 ;
    else ref = random(i+j) ; 
    ran = random(60) ;
    
                            
    if ( ran < ref  )
       { 
          if(random(2)==0)                  
              command("cast sleet on "+victim_name); 
          else 
              command("cast fireball on "+victim_name);
          
          return 1 ;
        }
    else 
          return 0 ;

}

//    There are 5 kind of quests for the first quest of asterism
//    and who level > 9 got a chance to do quest #2 ,3 , 4 
//    and once when player ask to do quest , have no chance to change

void quest1(object who)
{
   int a,b ;
   string cmsg,msg ;
   if(done)
     { write(
              "ŷ��Ц��Ц˵:лл��Ĺ���,�����Ѿ��б��˰�æ����ˡ�\n"
             );
       this_player()->delete("astr") ;
       this_player()->delete_temp("astr") ;
       return ;
      }      
   
   if( ( (int)this_player()->query_level() ) < 15 )
      { write(
               "ŷ�𰲳��Ͽ��˿���֮��,ҡ��ҡͷ��û���κα�ʾ��\n") ;  
        return ;
       }
   
   a = random(5) ;              
                 
   if( !( !this_player()->query("astr/questa") ) )
      a = this_player()->query("astr/questa") ;
     
   this_player()->set_temp("astr/quest1",1);
   this_player()->set("astr/questa",a);
   
     cmsg =
            "����ŷ�𰲸�����˵:\n"
            "�ҵ��ٻ�ħ����Ҫ�õ������ﲻ����,�����˸�ȥ����.\n"
            "ֻ�ǵ���ĳ��ҽ�����ҵġ�������ҵ������ʿ���\n"
            "����·ǳ���Ҫ,������æ��\n";
     write(
           cmsg  );
     return ;
}

int quest1a(object who)
{
   int a,b ;
   string cmsg,msg ;
     
   a = this_player()->query("astr/questa");
   b = this_player()->query_temp("astr/quest1");
      
   if(!a || !b || b <2)
      return notify_fail(
             "����˵ɶ??��һ�䶼��������\n"  ) ;
   
   if(random(2)==1)
      {
        who->set_temp("astr/quest1",3);
        cmsg =
            "����ŷ�𰲸�����˵:\n"
               "�Ҳ�����˵�����ֶ�����Ҳ����¶���С���ܰ��㡣\n"
            "����̸̸�����õ�һ���������Ǿ��鷳���ˡ�\n";
       }
   else
      {
        who->set_temp("astr/quest1",31);  
        cmsg =
            "ŷ�𰲳��ϸ�����˵ :\n"
            "      ��˵��ңԶ�Ķ���ס��һλ��ֲ������ĵõĸ���,\n"
            "      Ҳ������֪��һЩ�¡�\n" ;
       }
            
   write(  cmsg  );
   return  1;
}

void die()
{
     int i ;
     object scroll,killer,*player ;
     
     player = users() ;
     killer = query("last_attacker") ;
     scroll = new("/d/mage/tower/obj/fb7_scroll") ;
     scroll->set("prevent_drop",1) ;
     scroll->set("prevent_insert",1) ;
     scroll->move(environment(this_object())) ;    
     
     if (killer)
     for(i=0;i<sizeof(player);i++)
       {
          tell_object(player[i],"��մ���ŷ�𰲵�̾Ϣ�� : ��!!! ��Ȼ���"+
                killer->query("c_name")+"֮�֣����Ǹ�������ʱ���ˡ�\n") ;
        } 

     ::die(1) ;
}


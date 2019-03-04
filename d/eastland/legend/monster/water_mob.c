#include <mudlib.h>

inherit MONSTER;
void die();
int calloutcheck = 0;
string laugh,*action =
     ({ "%sָ��%s�ģأ�Ц��ֱ����������\n",
        "%s��%s������������ȥ���ô󶦡���������\n",
        "%sװ��һ������С����ӣ�����%sҡͷ���ԡ�\n",
        "%sһƨ�����ڵ��ϣ�ָ��%s���������Ŀ���������\n",
        "%s�������Ϳ%s������\n" }) ;

void create()
{       
	::create();
	set_level(19);
	set_name( "Water Beast", "��֧��" );
	add( "id", ({ "beast","water beast"}) );
	set_short( "ˮ�� ��֧��" );
	set_long(@C_LONG
����һ֧���Ӧ������Ĺ���, ��״��Գ��, ��ͷ��, ������, ���Դ�, ������,
����ѩ��, �۾����������, ���������ֻ��, ������������аٳ߳�, ������
����ȴ������㡣
C_LONG
);
        set("killer",1);
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 30 );
	set_skill( "unarmed", 100);
	set_natural_armor( 30, 1 );
	set_natural_weapon( 90, 40, 40 );
	set("locked",0);
	set("faint",0);
	set( "time_to_heal", 20 );
	set( "max_hp", 2500 );
	set( "hit_points", 2500 );
	set( "gender","male" );
	set( "alignment",-1000 );
        set("stun_difficulty",100);
        set("special_defense", 
          ([ "all": 30,"none":30]) );
        set("aim_difficulty",
          (["critical":100]) );
        set("tactic_func","my_tactic");        
}  
void init()
{
    ::init();
    add_action("do_joke","joke");
}

int do_joke(string arg)
{ 
   object player;
   player=this_player();
   laugh = set_color(action[random(sizeof(action))],"HIY");
   tell_object(player,
     "\n�����۹�������,��֧��������Ц��˵:���ѵ���֪�� joke ����������˭��?\n\n");
   tell_room(environment(this_object()),
         sprintf(laugh,"��֧��",player->query("c_name")));
   kill_ob(player);
   player->block_attack(6);
   player->set_temp("msg_stop_attack",
       "( ������Ц�û���û�����޷������� )\n" );
   return 1;
}
int my_tactic()
{
    object *victim;
    int i;     

    if ( !victim=query_attackers() ) return 0;
    if (random(10)>1) return 0;

    laugh = set_color(action[random(sizeof(action))],"HIY");
    tell_room(environment(this_object()),
       sprintf(laugh,"��֧��","���й������ĵ���"));
    for (i=0;i<sizeof(victim);i++) {
       victim[i]->block_attack(4);
       victim[i]->set_temp("msg_stop_attack",
          "( ������Ц�û���û�����޷������� )\n" );
    }
    return 0;
}
void recover_or_die(object ob)
{
   object env;
   calloutcheck=0;
   env=environment(ob);
   if ( !ob->query("locked") ) {  
      tell_room(env,"\n��Ȼһ�����,��֧���ֻ��˹���...\n\n");
      ob->set("hit_points",2500);
      ob->set("no_attack",0);
      ob->set("killer",1);
      ob->set("faint",0);
   }
   else 
     die(); 
}
void die()
{       
    object killer,obj;
    int wine;
    
    if ( !query("locked") ) {
       set("killer",0);
       set("no_attack",1);    
       cease_all_attacks();
       clean_up_attackers();
       set("hit_points",1); 
       tell_room(environment(this_object()),"��֧��һ������,�赹�ڵ���!!\n");
       set("faint",1);
       if (!calloutcheck) {
         call_out("recover_or_die",60,this_object());  	
         calloutcheck=1;   
       }
    }
    else 
    ::die();
}

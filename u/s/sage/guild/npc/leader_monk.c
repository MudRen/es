#include "saulin_monk.c"

void create()
{
        ::create();
        set_level(19);
        set_name( "leader", "少林寺方丈 慧空大师" );
        add ("id", ({ "leader","monk" }) );
        set_short( "少林寺方丈 慧空大师");
        set("unit","位");
        set_long(@C_LONG
慧空大师是少林寺的方丈，虽然年纪已经很大，可是因为修练少林内功\宝典
易筋经的关系，看起来还像壮年。仁慈宽厚的他堪称是泽被天下。他长年诵
经念佛，规劝世人向善，对於作恶多端的人也一定会加以开导。
C_LONG
        );
        set( "inquiry", ([
              "cave" : ({@HERB

   众生院？那是本寺专门用来安置别派高手的地方，凡是本派有大事发生
   不能立时让心存敌意的别派高手下山时，只好将他们暂时安置在那里，
   说来惭愧。那原本是後山的一个天然地穴，现在由敝派的三位高僧把守
   ，负责把意图劫人的高手驱离。
HERB
        }) ]) );
        set("alignment",2000);
        set("wealth/gold",250);
        set("gender", "male");
        set("race", "human");
        set("max_hp", 1000);
        set("max_fp", 600);
        set("hit_points", 1000);
        set("force_points", 600);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_natural_weapon( -5, 4, 10 );
	set_natural_armor( 50, 25 );
        set_temp("detect_hide",1);
        set("special_defense", ([ "all":70, "none":60, "monk":25 ]) );
        set("aim_difficulty", ([ "critical":65, "vascular":80, ]) );
        set_skill("bo",100);
        set_skill("parry", 90);
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
        wield_weapon( SAULIN_OBJ"staff1" );
        equip_armor( SAULIN_OBJ"necklace01" );
        equip_armor( SAULIN_OBJ"cloth1" );
        equip_armor( SAULIN_OBJ"shield1" );
        equip_armor( SAULIN_OBJ"glove2" );
        equip_armor( SAULIN_OBJ"ring1" );
	set("tactic_func","my_tactic");
}

int my_tactic()
{
	object *ob;
	int  i;
	
        if( random(25) > 3 ) return 0;
        	if( random(5) > 1 ) { 
        		tell_room( environment(this_object()), @MSG1
慧空大师喃喃道：「施主 !! 您这又是何苦呢？」他垂首合十默念心经真言 ..
突然一团团银白色的光芒围绕著他，他的伤口竟然复元了 !!

MSG1
			, this_object()
        		);
        		this_object()->receive_healing(80);
        		return 1; }
        	else {
        		tell_room( environment(this_object()), @MSG2
慧空大师突然声如宏钟大喊一声道： 「 呔 ！！ 」....

你受到一阵强烈的冲击，不由自主地倒退三步 !!

MSG2
			, this_object()
        		);
        		ob = this_object()->query_attackers();
        		i = sizeof(ob);
        		while(i--) {
        			ob[i]->block_attack(6);
        			ob[i]->set_temp("msg_stop_attack",
        				"( 你脑中一片混乱，无法攻击 ！ )\n" );
        			}	
        		return 1; }
}


int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "bonze" ) return 1;
   return 0;
}

int special_attack()
{
    object victim,*guard;
    int i;
    
    victim = query_attacker();
    if(!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner",this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room(environment(this_object()),
        "武僧大喊：师兄弟们，有人对师父不客气，快来保护师父！\n"
      );
      guard[i]->kill_ob(victim);
    }
    return 1;
}

void init()
{
   ::init();
   add_action("report_master","report");
}

int report_master()
{
    if( (int)(this_player()->query_temp("book_quest/step"))==2 ) {
    	tell_object(this_player(),@REPORT
慧空大师合十道：阿弥陀佛!!竟然有这种事情？这真是敝寺用人不当了，多谢
施主!!老纳立刻命人将那火工头陀送交 ...他并非本寺弟子，不能送戒律院惩
处，那只好先送入众生院(cave)。
此外，可否请施主代为询问楞枷经的下落，唉～。
REPORT
        );
   	if (this_player()->query("class")!="monk") 
	    tell_object(this_player(),"多谢施主帮忙找出真相，不胜感激！");
        this_player()->set_temp("book_quest/step",3);
        return 1;
	}
    if( (int)(this_player()->query_temp("book_quest/step"))==4 ) {
	tell_object(this_player(),@REPORT
慧空大师合十说道：阿弥陀佛!!多谢施主替本寺寻回经书, 敝寺上下同感大恩....
                  对了!!可否劳烦施主转告觉远不必再继续挑水了(release),
                  阿弥陀佛!!
REPORT
        );
         present("sutra",this_player())->remove();
         this_player()->set_temp("book_quest/step",5);
         return 1;
          }
	return 0;
}

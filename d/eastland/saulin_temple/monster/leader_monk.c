#include "saulin_monk.c"

void create()
{
        ::create();
        set_level(19);
        set_name( "leader", "�����·��� �ۿմ�ʦ" );
        add ("id", ({ "leader","monk" }) );
        set_short( "�����·��� �ۿմ�ʦ");
        set("unit","λ");
        set_long(@C_LONG
�ۿմ�ʦ�������µķ��ɣ���Ȼ����Ѿ��ܴ󣬿�����Ϊ���������ڹ�\����
�׽�Ĺ�ϵ������������׳�ꡣ�ʴȿ�����������������¡���������
����𣬹�Ȱ�������ƣ���������˵���Ҳһ������Կ�����
C_LONG
        );
        set( "inquiry", ([
              "cave" : ({@HERB

   ����Ժ�����Ǳ���ר���������ñ��ɸ��ֵĵط������Ǳ����д��·���
   ������ʱ���Ĵ����ı��ɸ�����ɽʱ��ֻ�ý�������ʱ���������
   ˵����������ԭ������ɽ��һ����Ȼ��Ѩ�������ɱ��ɵ���λ��ɮ����
   ���������ͼ���˵ĸ������롣
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
�ۿմ�ʦ�૵�����ʩ�� !! �������Ǻο��أ��������׺�ʮĬ���ľ����� ..
ͻȻһ��������ɫ�Ĺ�âΧ�������������˿ھ�Ȼ��Ԫ�� !!

MSG1
			, this_object()
        		);
        		this_object()->receive_healing(80);
        		return 1; }
        	else {
        		tell_room( environment(this_object()), @MSG2
�ۿմ�ʦͻȻ������Ӵ�һ������ �� ߾ ���� ��....

���ܵ�һ��ǿ�ҵĳ�������������ص������� !!

MSG2
			, this_object()
        		);
        		ob = this_object()->query_attackers();
        		i = sizeof(ob);
        		while(i--) {
        			ob[i]->block_attack(6);
        			ob[i]->set_temp("msg_stop_attack",
        				"( ������һƬ���ң��޷����� �� )\n" );
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
        "��ɮ�󺰣�ʦ�ֵ��ǣ����˶�ʦ������������������ʦ����\n"
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
�ۿմ�ʦ��ʮ���������ӷ�!!��Ȼ���������飿�����Ǳ������˲����ˣ���л
ʩ��!!�����������˽��ǻ�ͷ���ͽ� ...�����Ǳ��µ��ӣ������ͽ���Ժ��
������ֻ������������Ժ(cave)��
���⣬�ɷ���ʩ����Ϊѯ����Ͼ������䣬������
REPORT
        );
   	if (this_player()->query("class")!="monk") 
	    tell_object(this_player(),"��лʩ����æ�ҳ����࣬��ʤ�м���");
        this_player()->set_temp("book_quest/step",3);
        return 1;
	}
    if( (int)(this_player()->query_temp("book_quest/step"))==4 ) {
	tell_object(this_player(),@REPORT
�ۿմ�ʦ��ʮ˵���������ӷ�!!��лʩ���汾��Ѱ�ؾ���, ��������ͬ�д��....
                  ����!!�ɷ��ͷ�ʩ��ת���Զ�����ټ�����ˮ��(release),
                  �����ӷ�!!
REPORT
        );
         present("sutra",this_player())->remove();
         this_player()->set_temp("book_quest/step",5);
         return 1;
          }
	return 0;
}
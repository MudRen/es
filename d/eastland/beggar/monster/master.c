#include "/d/eastland/beggar/dony.h" 

object ob1;

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master of beggar","ؤ����� ��˷�" );
	add ("id", ({"master"}) );
	set_short( "ؤ����� ��˷�" );
	set_long(@C_LONG
��˷�������ԼĪ�塢��ʮ�����,����������������ͷ���,̫��Ѩ�߸߹���,˫
����������������, һ����֪���������������Ϊ��������Ϊ�˺�ˬ����������,
�ڰ����ĵ���Ե,ͬʱ������Ϊؤ��������书��Ϊ�������, һ�֡�����ʮ����
�����Ǵ�������޵���,��ʹ��������Ȼ�н�����˵����� ( trouble ) ��
C_LONG
	);
	set( "unit", "��" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 30 );
        set("weight",800);
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set_skill( "unarmed-parry",90);    
	set( "special_defense", ([ "all": 52,"none":50,
	     "monk":50,"scholar":50]) );
	set("aim_difficulty", 
	   ([ "critical":60, "vascular":80, "ganglion":80, "weakest":80 ]) );
	set("stun_difficulty",50);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 5000 );
	set("max_hp", 1200);
	set("hit_points",1200);
	set("max_fp",1000);
	set("force_points",1000);
	set_natural_armor( 30,70 );
	set_natural_weapon( 100,50,65);
	set( "wealth/gold", 300 );
        equip_armor(DARMOR"wind_cloth.c");
        equip_armor(DARMOR"wind_belt.c");
        equip_armor(DARMOR"wind_helmet.c");
        equip_armor(DARMOR"wind_ring.c");
	set_c_verbs( ({ "%s����ͦ����һ�� �����������%s���˹�ȥ", 
	                "%s���������ٿշ���ʹ�� ��Ǳ�����á� ����%s",
		        "%s��ǰһ�ݣ�ʹ�� ���������졻 ��%s���˶�ȥ",
		        "%s��ɶ�����������Ӱ��� ������ǬǬ�� ����%s", 
		        "%s����Ϊ�������� ��ͻ�������� �Ϳ�%s",
		        "%s��Ȼ��Цһ����ͻȻʹ�� ��ս����Ұ����˫������%s" }) );
        set( "inquiry", ([
                  "trouble":"@@ask_trouble",
                 "password":"@@ask_password",
                      "war":"@@ask_war"
              ]) );
	set( "tactic_func", "my_tactic" );
}

void ask_trouble( object asker )
{
    tell_object( asker ,
            "���� ��˷�˵��:��,ǰ���첻С���ҰѴ򹷰�����ʧ�ˡ��ڰ��д�\n"
            "                ��������������λ,���ҵ����ٹ������Ҫ���С���\n"
            "                ���䡻��,û�д򹷰������ҵĵ�λ�ͻ��ܵ�����\n"
            "                ,���ܰ����һ�����? �Ҽǵ��Ǻ�ȫ������ ( chan \n"
            "                ) ����������ʧ�ġ�\n"
            );
}
void ask_war()
{
write(@C_LONG
���� ��˷���Ȼ��:��,�ھ����ʮ����ǰ,�ҵ�ͬ��ʦ��ȫ�����򲻷�ʦ��������֮λ
                  ���ڸ���,ʱʱ�̶̿��в���֮ɫ,������������ʦ�ַ���Ҳ�Ͳ���
                  ȥ��ᡣû�뵽�ڶ�ʮ����,����Ȼ����,����������˶���չ��һ
                  �����Ĺ���,һһ��������ߵ���,��ʱ�ҵĴ����������ա�����, 
                  ����֮�������ں�, ��һ���ѱ�ŵ�����ֹ����Ϊ��Ҫ����������
                  ���ѱ�ĵ���,���ʦ�ֵĶ���Ϊ������֮λ,���Ķ���Ҳ��������
                  �н��������ҰѰ��ڵ��������ٵĺ������� ��ʱ����ͻ�С,�Ҳ�
                  û������˵�������׵���, �����벻����˵�������������ص�����
                  �׵�·��,ϣ��������Ҳ�������������ѱ����鷢���ˡ�
C_LONG
    );
}
int accept_item(object me, object item)
{
      string name,my_name;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
                  
      if (name!="dog blunt")
         return 0;
                                 
//      if( (int)me->query_quest_level("dony1") ) {
      if ( me->query("finish_dony") ) {
         tell_object( me,
            "���� ��˷�˵��:лл������������\n");
         return 0;
      }                                          
      
      if ( ( item->query("master") ) != my_name ) {
         tell_object( me,
            "���� ��˷�˵��:�����Ǵ��Ƕ����İ��Ӱ�?\n");
         command("give dog blunt to "+my_name);
      }
      else {
//         me->finish_quest("dony1", 1);
         me->set("finish_dony",1);
         me->gain_experience(3000);
         item->remove();
         tell_object( me,
            "���� ��˷��ӹ���İ���˵��:��ʲ�ᶼ����˵��,�������Ѿ�ȫ���������ˡ�\n"
            "                            ��,�����Ҹø���˵��һ�вŲ��������������\n"
            "                            ������лл����������!!\n");
         tell_object( me,
            "\n\n[������� ��˷� �����񣬵õ� 3000 �㾭��]\n\n");
         if ( ( me->query("class") ) =="scholar" ) {
            tell_object( me,
              "���� ��˷�˵��:����,�һ���һ����������½�����Ƕ�,�����ȥ���ʿ���\n");
            command("grin "+my_name);}
      }
         return 1;
}
void ask_password( object asker )
{
       if ( present("password",asker) ){
       command("look "+asker->query("name"));
       tell_object( asker,
         "���� ��˷�˵��:�����ϲ�������������?\n");
       return ;  
    }
    if ( query("be_asked") ){
       command("sigh "+asker->query("name"));
       tell_object( asker,
         "���� ��˷�˵��:��������,�ҲŰ����͸�����\n");
       return ;
    }
    if ( asker->query_temp("wu_asked")){
       tell_object( asker ,
            "���� ��˷�˵��:Ŷ,��Ҫ����?����,��ҪŪ��ม�\n");
       ob1=new(DITEM"password");
       ob1->move(this_object());
       command("give password to "+asker->query("name"));    
       set("be_asked",1);
       call_out("recover",1800,this_object());
       return ;
    } 
    tell_object( asker ,
      "���� ��˷�˵��:С����û����ʲ������?ȥȥȥ.\n");
}
void recover( object obj)
{
    obj->delete("be_asked");
}

int my_tactic()
{
     object victim,*t_item,*wea1,*wea2;
     int i;

	if (!(victim= query_attacker())) return 0;
	
	if ( query("force_points") < 100 ) set("force_points",1000);
	
	if( random(10)>8 ){
	   tell_room(environment(this_object()),
              "��˷����һ������ʽ�������лڡ����е�ǰ����"
              +(string)victim->query("c_name")+"��ɽ��������\n\n",victim);
           tell_object(victim,
              "��˷����һ������ʽ�������лڡ����е�ǰ�����㹥��,��ʱ��е��ؿ������ޱ�!!\n\n");
           victim->receive_special_damage("fire",50);
       	   report(this_object(),victim);
              wea1=victim->query("weapon1");
              wea2=victim->query("weapon2");
              if (wea1) wea1->unwield(1);
              if (wea2) wea2->unwield(1);
          return 1;
        }
       else { return 0;}       
}

#include "../dony.h"

inherit MONSTER; 

void  create()
{
	::create();
	set_level(18);
	set_name( "japan fighter", "����" );
	add ("id", ({ "japan", "fighter" }) );
        set_short( "�����ʿ ����" );
	set("unit","λ");
        set_long(@C_LONG
������һϮ��ɫ��װ, ȫ������ֻ¶���۾��Ĳ��ֶ������������۾���,�����
����һ˫����Ұ�޵��׺�Ŀ��,�ƺ�Ҫ����������¸�������ɱ�˵ļ�����һ����
,ֻҪ��������,�����Ǹ��˲�������ͻ�����,����������״����ޱȡ���������
���ĳ��, �ƺ�����ִ��ĳ������ 
C_LONG	
	);
        set("weight",680);
	set("alignment",-4000);
	set("wealth/gold",100);
	set_perm_stat("int", 23);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 30);
	set_perm_stat("kar",21);
	set("max_hp",550);
	set("hit_points",550);
	set_natural_weapon( 39, 15, 25 );
	set_natural_armor( 30,45 );
	set ("gender", "male");
	set ("race", "human");
	set_skill("parry",70);
	set_skill("dodge",80);
        set_skill("longblade",70);
	set_skill("anatomlogy",100);
        set("aiming_loc","weakest");
        set("special_defense", ([ 
              "divine": -20,"evil":30,"none":30]) );
        set("aim_difficulty",
              (["critical":80,"vascular":40,"ganglion":50,"weakest":80]) );
	wield_weapon(DWEAPON"katana");      
	equip_armor(DARMOR"japan_cloth");
        set( "inquiry", ([
              "chan":"@@ask_chan"
        ]) );
        set( "tactic_func", "my_tactic" );
}
void ask_chan( object asker )
{
   tell_object( asker ,
      "����˵��:����ȫ������������?������û�и�����˵��һ��Ҫ��Щʲ��?\n");
   return ;   
} 
int accept_item(object me, object item)
{
      string name,my_name;
            
      name=(string)item->query("name");
      my_name=(string)me->query("name");
      
      if (name!="a white letter")
          return 0;
      
      if ( ( name=="a white letter" )&&( this_object()->query("be_asked") ) )
      {
         tell_object(me,
            "����˵��:��Ӵ,������,�Ұ�Կ�׸�������!!���׷!!\n");
         command("give a white letter to "+my_name);      
         return 1;
      }
      if ( ( item->query("master") ) != my_name ) {                               
         tell_object( me,
           "����˵��:�����Ǵ��Ƕ����ż���?\n");
         command("give a white letter to "+my_name);  
      } 
      else {
         tell_object( me,
           "���½ӹ�����ż�˼����һ�����\n");
         item->remove();
         call_out("recover1",2,me);
         this_object()->set("be_asked",1);
         call_out("recover2",1800,this_object());
      }

}
void recover1( object obj )
{
     object ob1;
     ob1=new(DITEM"key.c");
     tell_object( obj ,
       "����˵��:Ŷ,ԭ����ȫ������˵Ҫ������Կ�׵��,��ȥ��!������Ҫ��\n"
       "         ���,������ȥŪ���ġ�\n");
     ob1->move(obj);   
}
void recover2( object obj )
{
     obj->delete("be_asked"); 
}
int my_tactic()
{
    object env,me,victim;
    string my_name,vic_name;  
      
      victim=query_attacker();
      me = this_object();
      my_name=(string)me->query("c_name");
      vic_name=(string)victim->query("c_name");
      env = environment(me);
       
      if ( !victim ) return 0;
        
      switch( random(40) ) {
      case 1..3 : 
                victim->receive_special_damage("evil",40);
                tell_room(env,my_name+
                      "�������칭Ҫ��,���ڰ��Ĳ���Ϊһ����������"+vic_name+"��ҪѨ!!\n\n",victim);             
                tell_object(victim,my_name+
                      "�������칭Ҫ��,���ڰ��Ĳ���Ϊһ�������������ҪѨ!!\n\n");
                report(this_object(),victim);
                return 1;
      case 4 :  
                victim->receive_damage(25);
                tell_room(env,my_name+
                       "�������ͳ�һ֧ʮ�ַ�������"+vic_name+"������!!\n\n",victim);
                tell_object(victim,my_name+
                       "�������ͳ�һ֧ʮ�ַ����䵽������!!\n\n");                       
                report(this_object(),victim);
                return 1;       
      case 5..6 :
                victim->receive_damage(38);
                tell_room(env,my_name+
                       "�û���ʮ������,���벻���ķ�λ,��"+vic_name+"һ��ʹ��!!\n\n",victim);
                tell_object(victim,my_name+
                       "�û���ʮ������,�����벻���ķ�λ,����һ��ʹ��!!\n\n");
                report(this_object(),victim);
                return 1;  
      default :
                return 0;
      }
}

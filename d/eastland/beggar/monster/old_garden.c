#include "../dony.h"

inherit MONSTER;
 
int receive_damage(int damage);
void create()
{
        object ob1;
	::create();
	set_level(19);
	set_name( "Old gardener", "��Ժ��" );
	add( "id", ({ "old","gardener" }) );
        set_short( "���� ��Ժ��" );
	set_long(@C_LONG
��Ժ���ǡ��µ��塻����ٵ���, �ഫ����������������֮��,��ù鹦�����
���о���������֮������Ժ��ƽʱ�ƹ����ô��СС������, ����������Ϊ�ˡ�
ؤ�������æ�ò��ɿ���,æ��æ��������Ȼ��������˿��������Щ�����С
�����!!
C_LONG	
	);
        set("hit_points",2000);
        set("max_hp",2000);    
        set("weight",700);
        set("wealth/gold",200);
        set_perm_stat("str",25);
        set_perm_stat("int",35);
        set_perm_stat("dex",23);
        set_perm_stat("kar",40);
        set_natural_armor(70,0);
        set_natural_weapon(31,15,25);
        set_skill("dodge",60);
        set_skill("blunt",60);
        set( "race", "human" );
	set( "gender","male");
	set( "unit", "λ" );
        set_temp("be_joke",10);
        set("aim_difficulty",
           (["critical":200,"vascular":70,"ganglion":50,"weakest":60]) );
        set("stun_difficulty",90);
        
        wield_weapon(DWEAPON"broom");
        equip_armor(DARMOR"enforcer_robe");
        ob1 = new( DITEM"life_ball" );
        ob1->move( this_object() );
        set( "inquiry", ([
                   "hau":"@@ask_hau",
               "history":"@@ask_history", 
                "before":"@@ask_before", 
             "continue1":"@@ask_continue1",      
             "continue2":"@@ask_continue2",
             "continue3":"@@ask_continue3",
                   "uki":"@@ask_uki",
              "worship":"@@ask_worship"       
                    ]) );
}
void init()
{
    ::init();
    add_action("do_backstab","backstab");
}
    
void do_backstab(string str)
{
    tell_object(this_player(),"�� bs ? \n");
    this_player()->set_temp("block_command",1);
    call_out("recover1",5,this_player());
}
void recover1(object obj)
{
    obj->delete_temp("block_command");
    tell_object(obj,"�벻Ҫ��������ʥ�ĵط��������¡�\n");
}
void ask_hau(object asker)
{
   if ( asker->query_temp("uki_asked") ) {
      tell_object( asker,
        "���� ��Ժ��˵��:�,���ʻ��������˵Ĳ�?\n"
        "���� ��Ժ��˵��:��ʵСѩ��˵��û�д���,ֻ�Ǿ�ת����������������Ҫһ\n"
        "                ������ҩ����ܴﵽ�������ͺϡ��ľ���,��Ч�÷��ӵ���\n"
        "                ��,���������������\n"
        "���� ��Ժ��̾��:��,�ұ��ж������Ƶġ����������������Ժ���������ϴ�\n"                         
        "                ���������ͺϡ��ľ���,���ǲ�֪����ʧ������.....\n\n"
        "���� ��Ժ������һ���......\n\n");
        asker->set_temp("old_asked",1);
        call_out("recover2",10,asker);
   } 
   else 
      tell_object( asker,
        "���� ��Ժ��˵��:�Ҳ������\n"
      );     
}
void ask_history(object asker)
{
write(@C_LONG
��Ժ��˵��:���ʡ�н���塻����ʷ?�ǿ���Ҫ�Ӻܾ���ǰ˵��(before)?
C_LONG
      );
}
void ask_before(object asker)
{
write(@C_LONG
��Ժ��˵��:    ��Լ�ڶ��ٰ�ʮ��ǰ,��ԭ�����ϸ����������;����ǧ�˵Ĵ�����˵
           �ж������ٸ�;С��һ�������˵�С���Ÿ��ǲ���ǧ��,һʱ����ӿ��Ϯ����
           ���ֵ�ÿһ�����䡣
               Ȼ��, ѧ������ѧ���˶�֪��,��������޵�������Դ֮��,һ�����ɶ�
           ��������Ե��ܷ�������˵���������������� ���������Ķ����---��
           �������������ܹ����һ�С���֧ʹ֮��, �����е���֮�����߱˴����
           ͬ����������֥��С�¶���ʹ�˴󶯸ɷ������ǵ�������֮������,��������
           Щ��û���,����з�һ������, ��������һ�ɵĸ������������һҹ֮��
           Ϥ����ʧ�����������������˻ῴ����������м��Ե�ͣ,��ͣ�Ľ����Ȼ��
           ������ʹ֮�ն�,���˴��ܻ����л����ٵ�϶�����, ��������Щ����춵�
           ͣ�����,��������������������������Ķ�����
��Ժ������һ��,����һ�ڲ�,˵��:Ҫ����(continue1)?           
C_LONG
    );
}
void ask_continue1(object asker)
{
write(@C_LONG
��Ժ������˵��:  ��ʱ, ����Щ��춡��ϴ󡻵����ɳ�����ѡһ�������������쵼��
           ��,һʱ�ĵý������˵�֧�֡�����,����Ϊ����һ������ϯλ���Ǵ��ͷ��
           Ѫ��,������ȴ����һ�������Ѫ�ȡ��������ϵ���,ѡ��������������ȴ��
           ��������������ʮ��İ���, ���������������Ŭ������ʹ��!��ʮ��֮��,
           ��ѧ��ʽ˥΢, ��������Ҳ�Ҳ���һ�����Ե�����������֮λ����,���,��
           �����,������һ������ĺƽ١�
��Ժ��˵��:�Բ���,���ֿ��ˡ���Ժ������һ�ڲ衣
��Ժ��˵��:Ҫ����(continue2)?                        
C_LONG
     );
}
void ask_continue2(object asker)
{
write(@C_LONG
��Ժ��˵��:   ��ʱ��ֵ��������,��͢������޷���������ԭ��������ͳ��֮��,������
          ������Щ���������ɱ,��������Թۡ���Ϊ��ǧ���ҵ,�Ʊ�Ҫ�����������
          ���������������,��͢�ƻ���ı,�������ú�������׼��, ��ǡ��ѡ������
          �����ల�����ʮ��,����������ϡ�������ʮ��֮��,�����ֿ�ʼ�Զ����Ҹ�
          �˳�͢һ����õĻ���,��͢Ҳ֪���������һ�ټ�ʧ,������ӥ��צ����һ��
          ��������ɡ����ֲ��������в����,����˳�ӹ�˳������ò���,����������
          ������,�ֶμ���ݶ�,����������֮��,���������ʮ֮ȥ��,��ʱ������һ��
          ɢɳ,������һ�������ֵܵ����˳�͢�Ĺ�����?
��Ժ��˵��:Ҫ����(continun3)?                            
C_LONG
     );
}
void ask_continue3(object asker)
{
write(@C_LONG
��Ժ��˵������,��ɫ�е�Ұ�:   λ���µ�һ����ؤ�������ٳ�͢�Ⲩ�Ĺ���֮��,��
          ��Ҳ��Щ�ݱ�,���ο������廹δ����֮ǰ,ؤ�ﴦ���ڸ���������;���֮��,
          ؤ���ֵ����������±�ʾ��������ͳ��,���־ٶ����ѱ���͢��Ϊ���ж�,����
          ��â�̡�����,ؤ�����볯͢��һ����Ҫ�ľ�ս��,�԰˴���������,Ϥ������,
          ����һ���ߴ����ÿ�,���Ա�ס������Ҫ������, ����춳�͢����ʤ���Ĺ���,
          ����ֻ���˾ӵ�һ������֮��,ٹ������, ��������֮������Ϊ��н���塻ȡ'
          ��н����'֮�⡣��������,��Ȼ����ѡһλ����������һ�е��������ӷ���
          ,������,ؤ�������ﰲ������,�󲿷ݵĵ���Ҳ��Ȣ������,����������һ�ٶ�
          �ꡣ����,ʮ����ǰ.......
�㿴��Ժ�������Ӳ��������˵��ȥ,����������������һ�������ҵ��¡�                    
C_LONG
    );
}
void ask_uki()
{
write(@C_LONG
��Ժ��˵��:Сѩ����һ���ܲ����Ů����,��Щ��������,����,���ڵ��������治֪��
           �������?
C_LONG
    );           
}
void recover2(object obj)
{
      tell_object( obj,
        "���� ��Ժ��˵��:�Ҽǵ��ڡ��꼦����Ͳ�����,�����ȥ���ҡ�\n");
}
void ask_worship()
{
write(@C_LONG
���� ��Ժ��˵��:���ʼ������,���Ǵ���һ��һ�ȵ�ʢ��,�������м����е��˿��˹�
                ȥһ�����Ĺ��������о���,�����¾ɰ�������Ҳ������ʱ��ɡ�ͨ��,
                �ڴ���϶�������һЩ���ֳ�����ʿ,��, �Ѿ��������������������,
                ������Ҫ��ȥ����Щ�����ϵ�����?
C_LONG
      );
}
int receive_damage(int damage)
{
    int hits;
    object victim,act_ob;
    string mob_name,vic_name;
    
    victim=query_attacker();
    if ( !victim ) return ::receive_damage(damage);
    mob_name=this_object()->query("c_name");
    vic_name=victim->query("c_name");
    
    act_ob = previous_object();
    if( act_ob && living(act_ob) ) set("last_attacker", act_ob);

    if ( ( victim->query("class")=="mage" ) )
       victim->set("spell_points",0);
    
    if (random(6)>2){
       tell_room( environment(this_object()),set_color(
            "��!!"+mob_name+"����Ų���ķ�,�����ܵ����˺�Ϥ����"+vic_name+"����!!\n","HIW"),victim);
       tell_object( victim, set_color(
            "��!!"+mob_name+"����Ų���ķ�,�����ܵ����˺�Ϥ���������!!\n","HIW"));         
       hits = (int)victim->query("hit_points");
       hits -= damage;
       if( hits < 1 && wizardp(victim) && victim->query("immortal") )
          hits = (int)victim->query("max_hp");
       victim->set("hit_points",hits);
    }
    else{
       hits= (int)this_object()->query("hit_points");
       hits-=damage;           
       this_object()->set("hit_points",hits);
    }
    return 1;
}                                  

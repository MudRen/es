//#pragma save_binary
//   create by Indra@Eastern_Story
//
//  ������(������\) , ��spellpower �ĳ�..
//  
#include <mudlib.h>
#include "/d/healer/healer.h"

inherit DAEMON;

int help();
string int_to_str(int arg) ;

int remove_block(object obj)
{
   obj->delete_temp("block_command") ;
   return 1 ;
}

int cmd_douin(string str)
{
    int eff_lv,eff_no,sp_cost,skill,needed ;
    string type,who,temp,*acu_pts,eff_file;
    object target,me ;

	skill = this_player()->query("dou-in") ;         
        if(!skill)
           return notify_fail("�㻹û��������, ��֪�������ķ�����\n") ; 

        temp = int_to_str(skill) ;

        if( !str ) 
          {
             write(sprintf("�������Ŀǰ����%s��\n",temp)) ;
             return 1 ; 
           }
           
        if( (int)this_player()->query("stop_attack")>0 )
             return notify_fail (
                "( ����һ��������û����ɣ��޷�ר�������� )\n" );
        
                                                    
	if( sscanf( str, "%s on %s", type,who )==2 ) 
	        {  
	           who = lower_case(who) ;
	           if(who=="me") target = this_player() ;
	           else if(!target=present(who,environment(this_player()) ))
                          {
	                     write("���뵼˭���� ?\n") ;
                             return 1 ;
                           }   
	         }
	else if( sscanf( str, "%s", type )==1 ) target = this_player() ;
 
        me = this_player() ;       
        if(!( !(me->query_current_attacker()) ))
                return notify_fail("�㻹��ս����,ûʱ��ͣ����������\n");
         
	if( !me->query("vision") )
      		return notify_fail("�㿴����Ŀ�꣬û�취���� !!\n"); 
	
	if( me->query("weapon1") && ( me->query("weapon2") ||
	     me->query("armor/shield") ) )
	    return notify_fail( "��û�ж��ŵ��������� !!\n" );

        if( me->query_temp("no_concentrate"))
            return notify_fail("���ע���������ܼ���,�޷�ר�ġ�\n") ;

        if(!( !(target->query_current_attacker()) ))
                return notify_fail("���Ŀ�껹��ս����,ûʱ��ͣ�������㵼����\n");
       
        switch(type)
               {
                 case "ultra"   : eff_lv = 7; break;               
                 case "super"   : eff_lv = 6; break;
		 case "max"     : eff_lv = 5; break;
		 case "regular" : eff_lv = 4; break;
		 case "normal"  : eff_lv = 3; break;
		 case "minor"   : eff_lv = 2; break;
		 case "mini"    : eff_lv = 1; break;
		 default : return help();
		}
	

        acu_pts = target->query_temp("acupuncted_pts") ;
        if(!(acu_pts)) return notify_fail
            ("�⵼��,��ʩ���ǿ�����ʲ��Ч���ġ�\n") ;
     
        eff_no  = USE_POINTS->check_allwork(acu_pts) ;
        if(eff_no!=0)
          {  
             eff_file = USE_POINTS->query_eff_file(eff_no) ; 
        
             if( file_size( eff_file + ".c" ) == -1 )
               return notify_fail("����е�Ч�����ݵ�������,������ʦ��ϵ��\n") ;
           }
        else
          {
             sp_cost = eff_lv*20 ;
             if((int)this_player()->query("spell_points")<sp_cost)
                  return notify_fail("�����еľ��������ͳ�����ǿ������");

             this_player()->set_temp("block_command",1) ;
             this_player()->receive_damage(eff_lv*10) ;
             this_player()->add("spell_points",-sp_cost) ;
             this_player()->block_attack(3) ;
             me->set_temp("msg_stop_attack","�����ȫ���ʹ,�޷�������\n" ) ;
             target->receive_damage(eff_lv*3) ;             
             target->delete_temp("acupuncted_pts") ;
             
             tell_object( target,
                "��������ڵ�Ѫ����ʼ��������������ͻȻ��ȫ��ʼ��ʹ....��\n"
                ) ;
                
             tell_room( environment(target),
                        sprintf("%s������ʼ����, �������Ҫ����Ѫ���ˡ�\n"
                       ,target->query("c_name")),target );
            
             tell_object( this_player(),
                "��ͻȻ���ֶԷ�Ѫ�����㼤������,�����������Ѿ�������....��\n"
                     );
             call_out("remove_block",5,this_player()) ;
             return 1 ;                          
          }    
        if(eff_lv>skill)
           return notify_fail("�����ڵ�����ֻѧ��"+ temp +"�� \n"+
                              "ǿҪ�ø��߲����, ����ֻ���к�����\n") ;
           
        sp_cost = eff_file->query_sp_cost(eff_lv,skill) ;
        if((int)this_player()->query("spell_points")<sp_cost)
           return notify_fail("�����еľ��������ͳ�����ǿ������") ;
        
        needed = eff_file->query_need_level() ;
        if(!needed) return notify_fail("Ч�����ݵ����𻵡�\n") ;
                 
        if( needed > eff_lv)
           {
              temp = int_to_str(needed) ;
              return notify_fail("Ҫ����Ч��,������Ҫ"+temp+"��������\n");
           }         
        this_player()->add("spell_points", -sp_cost );
        this_player()->gain_experience( eff_lv * 10 ) ;
        eff_file->acu_effect(eff_lv,target) ;

	return 1;
}

string int_to_str(int arg)
{
      string temp ;     
      switch(arg)
            {
              case 1 : temp = "�ڶ���"; break ;
              case 2 : temp = "���Ĳ�"; break ;                
              case 3 : temp = "������"; break ;              
              case 4 : temp = "�ڰ˲�"; break ;
              case 5 : temp = "��ʮ��"; break ;
              case 6 : temp = "��ʮ����"; break ;              
              case 7 : temp = "��ʮ�Ĳ�"; break ;
              default: temp = "�������,��Զ����" ;
            }
      return temp ; 
}

int help()
{
		write( @C_HELP
ָ���ʽ: douin [����] on [���]

  �����������ڵ�����, ҽ����������������Ϊ���������β�, ����
�ڶ�ʱ����ǿ�˵�ĳЩ��������ȷ�������Ѩ������ȷ��, �����ʩ��
��������������������, ʹ����ĵ�Ч��������̵�ʱ�������ֳ�����
�����������������趨Ϊ max, regular, normal, minor, mini  ����
һ�����, ��Խ�����ʱԽ��, ���ĵľ�����ҲԽ��, Ȼ����Ч��ҲԽ
�á�
    ֱ�Ӵ�douin ����֪����������ѧ��,����ʹ�õ���������
C_HELP
		);
    return 1;
}


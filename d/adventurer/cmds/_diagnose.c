//#pragma save_binary
#include <mudlib.h>
#include "/d/healer/healer.h"
 
inherit DAEMON;
 
int cmd_diagnose(string arg)
{
        object dest;
        int skill,hp,max_hp,i,limit,diff, referance;
        mapping conds,acups;
        string *cond_name,cond_str,*acup_name,acup_str,destname,msg,der;
 
 
        if( this_player()->query_level() < 5 )
                return notify_fail("�㵽���������?\n");
        if ( !arg || arg == "" ||
             !(dest = present(arg,environment(this_player()))) ) 
                return notify_fail("��Ҫ��˭��� ?\n");
 
        if ( ! living(dest) )
                return notify_fail("�������û��������\n");
        if ( (skill = this_player()->query_skill("diagnose")) == 0 ) 
                return notify_fail ("�㲢û��ѧ����ϵļ��ܡ�\n");
        conds = (mapping)dest->query("conditions");
        acups = (mapping)dest->query_temp("acup_effect");
        cond_str = "";
        if ( sizeof(conds) ) {
                cond_name = keys(conds);
                for( i=0, limit=sizeof(cond_name); i<limit; i++ ) {
                        if( cond_name[i][0] == '_' ) continue;
                        cond_str = sprintf("%s %s", cond_str, 
                                to_chinese(cond_name[i]));
                }
 
        }
        if ( cond_str == "" ) cond_str = "����";
        acup_str = "";
        if ( sizeof(acups) ) {
                acup_name = keys(acups);
                for( i=0, limit=sizeof(acup_name); i<limit; i++ ) {
                        if( acup_name[i][0] == '_' ) continue;
                        acup_str = sprintf("%s %s", acup_str,
                             USE_POINTS->query_effect_c_name(acup_name[i]));
                }
 
        }
        if ( acup_str == "" ) acup_str = "û�а��";
 
        hp = dest->query("hit_points");
        max_hp = dest->query("max_hp");
        if(!max_hp) return notify_fail("�������������,��������ʦ��\n") ;
 
//   ���ܳ��� 80 �Ͳ��� 5 Ϊ�ײ��ʾ          
        if( skill < 80 )       
          { 
            referance = (20 * hp) / max_hp;
            referance = 5 * referance ;
           } 
        else
            referance = (hp * 100) / max_hp  ;
        
//   �������ֵ        
        diff = 51 - skill/2 ;
        diff = random(diff);
 
        if(random(2)==1)
          { der = "��" ; 
            referance -= diff ; 
           }
        else
          {
            der = "��" ;
            referance += diff ;
           } 
           
        if( referance > 100 ) 
           { 
               diff = diff - ( referance - 100 ) ;
               referance = 100 ;
            }
        if( referance < 0 )
           {
               diff = diff - ( 0 - referance ) ;
               referance = 0 ;  
           }
        if(wizardp(this_player()))
           write( sprintf("���ԼΪ%s %d %% \n",der,diff) ) ;
 
        if( dest != this_player())
          {
            tell_object(dest,
                sprintf("%s���������һȦ, ���ﲻ֪���ֹ�Щʲ�ᶫ����\n",
                   this_player()->query("c_name"))
                   );
           }
        else
            return notify_fail("Ҫ֪���Լ���״��, �� Score �ͺ��� !!\n") ;          
 
        write( sprintf( "%s���ڵ�����Լʣ��%d %% , Ŀǰ������״�� %s \n"
                        "���������е����Ч��: %s��\n"
                ,dest->query("c_name"),referance,cond_str,acup_str));
        return 1;
}
 
 


// Created by Kyoko.
// modify by angel for monk guild... :P

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON ;

int gonfu_exists(string gonfu);

int help() ;

int cmd_eungon(string str)
{
	
         string type,targname,gonfu;
         int fp_cost,delay_time,skill,gonfu_level,kk;
         object code;
    
if( !str ) return help();

if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail ("( ����һ��������û����ɣ��޷�ʩչ��ʽ�� )\n");
 // if (this_player()->query_temp("gonfu_busy") )
        
if( this_player()->query_temp("no_enhant") ||
        this_player()->query("no_enhant") )
               return notify_fail( "����׼��ʹ����ʽʱ����Ȼ������ͻȻ����ȫʧ�ˡ�\n" );
if( environment(this_player())->query_temp("no_enhant") ||
         environment(this_player())->query("no_enhant") )
              return notify_fail( "���ﲻ��ʹ���κ���ʽ��\n" );
if (sscanf(str,"%s at %s", gonfu,targname)==2) 
   {
         if( undefinedp(this_player()->query("gonfus/"+gonfu)) )
	     return notify_fail( "�׳�!!! �������������\��\������\n");
	
   }
        
else{
        gonfu=str;
        targname= "NONE";
        if( undefinedp(this_player()->query("gonfus/"+gonfu)) ) 
            return notify_fail( "��������\�������? ������Ͳ������ֹ�\����! \n");

     }
code = GONFU_D->find_gonfu( gonfu );
        	       if( !code )
	        	return notify_fail( 
        	"û�����ֹ�\�� .... ��֪ͨ��ʦ���� bug ָ�����ʽ���ơ�\n");


	fp_cost = (int)code->query_fp_cost();
	delay_time = (int)code->query_delay_time();
	if( !fp_cost || (int)this_player()->query("force_points") < fp_cost )
		return notify_fail( "�������������\n");

        if ( (string)this_player()->query_temp("gonfu_now")==gonfu)
        return notify_fail( "��Ŀǰ����ʩչ���ֹ�\��  "); 


skill=this_player()->query_skill("inner-control");
if (random( fp_cost>100?100:fp_cost)  >  skill) {
      write ("����ͼ��������\... ��ʧ����..... \n");

      tell_room(environment(this_player()), 
        this_player()->query("c_name")+"ͻȻ���һ��... �ƺ��˹��������� \n",
        this_player() );
        this_player()->add("force_points", -fp_cost);
        return 1;
                                                         } else 
    { 
    gonfu_level=(int)this_player()->query("gonfus/"+gonfu); 
    this_player()->set_temp("gonfu_now", gonfu);
    this_player()->set_temp("gonfu_delay_time", delay_time);
       	if( code->eungon(gonfu_level,targname) )
          this_player()->add("force_points", -fp_cost );
	return 1;
    }
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
ָ���ʽ: eungon <��ʽ����> at <����>
      ��  eungon <��ʽ����>  // ����������Լ�����.... 

���ָ����������ʩչ��ʽ��������� gonfus ָ���Ŀǰ�Ѿ�ѧ�����ʽ�б�
C_HELP
		);
	else write ( @HELP
Usage:	eungon <gonfu name> at <mob>

This command let you enhant gonfus. You can type "gonfus" to see the 
gonfus you have learned.
HELP
    );
    return 1;
}

#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  ���������Ϊ���ε������� realname ���ǳɹ��ı�ʶ�ᴫ�ص�����     
        
	set_name("Standard Plant","��׼�Ĳ���ֲ��");     
	add( "id" , ({ "plant","tree","ivy" }) );        
	set_short("Standard Plant","��׼�Ĳ���ֲ��");    
	set_long(".." , "����������״������ֲ�\n");   
        
        set("c_realname","�ƴ���Ů");         // ��ұ��ϳɹ����ص�����
        set("realname","beauty");
	
   	set("unit","��");                     // ��,��,��.�����

   	set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

   	set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��
      
        set("herb_file","NULL") ;             //���������Ķ�������������
        set("herb_path","/d/healer/plant/");   //���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant
                                                
        set("skill_require",0) ;              //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",0);                    //�Ƿ񱻱��˽����ȵ�,0Ϊ��,1Ϊ��
       
        set("plant_type",0);                  //

}

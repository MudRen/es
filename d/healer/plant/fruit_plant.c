#include <mudlib.h>
inherit OBJECT;

void create()
{
   //  ���������Ϊ���ε������� realname ���ǳɹ��ı�ʶ�ᴫ�ص�����     
        
	set_short("@@query_c_name");    
        
        set("c_realname","������");         // ��ұ��ϳɹ����ص�����
        set("realname","fruit");
	
   	set("unit","��");                     // ��,��,��.�����

   	set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

   	set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��
      
        set("herb_file","fruit.c") ;   //���������Ķ�������������
        set("herb_path","/d/healer/reagent/");   //���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant
                                                
        set("skill_require",90) ;             //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",2);                    //�Ƿ񱻱��˽����ȵ�,0Ϊ��,1Ϊ��
       
        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;
  
  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;

  if (this_player()->query_stat("int") < 10 ) {
    set("id",({"plant","tree"}));
    set_long("����������������һ�������̫һ��, ������ǰǰ���ῴ�˺ü���,\n"
             "����˵������ʲ�᲻ͬ��\n");
    set_name("A plant","��ֵ���");         
    return "��ֵ���";
  }  
  else if ( ok== 1 ) {
    set("id",({"plant","tree"}) );
    set_long("��������ϸ�����Ľ��, ���ж����е伮�в�û���������\n��������"
	     "��Щ����(fruit),"
             "�������ҩ��, ��������(dig)һ���ȥ��\n");
    set_name("Plant","��֪������");          
    return "��֪������";
  }  
  else {
    set("id",({"plant","tree"}) );
    set_long("�������ڹ�������α��е�����֪ʶ, ���ж�����һ�ö�������ľ, \n"
             "������ȷ������, ����Ҫ��һ���ı�ʶ��\n");
    set_name("a plant","��������ľ");         
    return "��������ľ";
  }  
}      


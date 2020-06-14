namespace UnrealBuildTool.Rules 
{
    public class GoogleTestApp : ModuleRules
    {
        public GoogleTestApp(ReadOnlyTargetRules Target) : base(Target)     
        {                   
            PublicDependencyModuleNames.AddRange ( new string [] {  } );
         
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {           
                    "GoogleTest",
                    "ExampleGameCore"
                }
            );          
            PrivatePCHHeaderFile = "Private/GoogleTestApp.h";           
        }      
    }
}
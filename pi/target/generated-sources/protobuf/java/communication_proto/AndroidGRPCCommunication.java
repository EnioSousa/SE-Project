// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Communication.proto

package communication_proto;

public final class AndroidGRPCCommunication {
  private AndroidGRPCCommunication() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_protoCommunication_VoidConfirmation_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_protoCommunication_VoidConfirmation_fieldAccessorTable;
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_protoCommunication_State_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_protoCommunication_State_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\023Communication.proto\022\022protoCommunicatio" +
      "n\"*\n\020VoidConfirmation\022\026\n\016isConfirmation\030" +
      "\001 \001(\010\"\026\n\005State\022\r\n\005state\030\002 \001(\0052\272\001\n\rCommun" +
      "ication\022R\n\017getCurrentState\022$.protoCommun" +
      "ication.VoidConfirmation\032\031.protoCommunic" +
      "ation.State\022U\n\022requestStateChange\022\031.prot" +
      "oCommunication.State\032$.protoCommunicatio" +
      "n.VoidConfirmationB1\n\023communication_prot" +
      "oB\030AndroidGRPCCommunicationP\001b\006proto3"
    };
    descriptor = com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        });
    internal_static_protoCommunication_VoidConfirmation_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_protoCommunication_VoidConfirmation_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_protoCommunication_VoidConfirmation_descriptor,
        new java.lang.String[] { "IsConfirmation", });
    internal_static_protoCommunication_State_descriptor =
      getDescriptor().getMessageTypes().get(1);
    internal_static_protoCommunication_State_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_protoCommunication_State_descriptor,
        new java.lang.String[] { "State", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}

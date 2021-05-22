#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

const unsigned int module_bytes_len = 5576;
const extern unsigned char WASMER_METADATA[];

// Compiled Wasm function pointers ordered by function index: the order they
// appeared in in the Wasm module.
void wasmer_function__0(void);
void wasmer_function__1(void);
void wasmer_function__2(void);
void wasmer_function__3(void);
void wasmer_function__4(void);
void wasmer_function__5(void);
void wasmer_function__6(void);
void wasmer_function__7(void);
void wasmer_function__8(void);
void wasmer_function__9(void);
void wasmer_function__10(void);
void wasmer_function__11(void);
void wasmer_function__12(void);
void wasmer_function__13(void);
void wasmer_function__14(void);
void wasmer_function__15(void);
void wasmer_function__16(void);
void wasmer_function__17(void);
void wasmer_function__18(void);
void wasmer_function__19(void);
void wasmer_function__20(void);
void wasmer_function__21(void);
void wasmer_function__22(void);
void wasmer_function__23(void);
void wasmer_function__24(void);
const void* function_pointers[] = {
	(void*) wasmer_function__0,
	(void*) wasmer_function__1,
	(void*) wasmer_function__2,
	(void*) wasmer_function__3,
	(void*) wasmer_function__4,
	(void*) wasmer_function__5,
	(void*) wasmer_function__6,
	(void*) wasmer_function__7,
	(void*) wasmer_function__8,
	(void*) wasmer_function__9,
	(void*) wasmer_function__10,
	(void*) wasmer_function__11,
	(void*) wasmer_function__12,
	(void*) wasmer_function__13,
	(void*) wasmer_function__14,
	(void*) wasmer_function__15,
	(void*) wasmer_function__16,
	(void*) wasmer_function__17,
	(void*) wasmer_function__18,
	(void*) wasmer_function__19,
	(void*) wasmer_function__20,
	(void*) wasmer_function__21,
	(void*) wasmer_function__22,
	(void*) wasmer_function__23,
	(void*) wasmer_function__24,
};

// Trampolines (functions by which we can call into Wasm) ordered by signature.
// There is 1 trampoline per function signature in the order they appear in
// the Wasm module.
void wasmer_trampoline_function_call__0(void*, void*, void*);
void wasmer_trampoline_function_call__1(void*, void*, void*);
void wasmer_trampoline_function_call__2(void*, void*, void*);
void wasmer_trampoline_function_call__3(void*, void*, void*);
void wasmer_trampoline_function_call__4(void*, void*, void*);
void wasmer_trampoline_function_call__5(void*, void*, void*);
void wasmer_trampoline_function_call__6(void*, void*, void*);
void wasmer_trampoline_function_call__7(void*, void*, void*);
void wasmer_trampoline_function_call__8(void*, void*, void*);
void wasmer_trampoline_function_call__9(void*, void*, void*);
void wasmer_trampoline_function_call__10(void*, void*, void*);
void wasmer_trampoline_function_call__11(void*, void*, void*);
void wasmer_trampoline_function_call__12(void*, void*, void*);
const void* function_trampolines[] = {
	wasmer_trampoline_function_call__0,
	wasmer_trampoline_function_call__1,
	wasmer_trampoline_function_call__2,
	wasmer_trampoline_function_call__3,
	wasmer_trampoline_function_call__4,
	wasmer_trampoline_function_call__5,
	wasmer_trampoline_function_call__6,
	wasmer_trampoline_function_call__7,
	wasmer_trampoline_function_call__8,
	wasmer_trampoline_function_call__9,
	wasmer_trampoline_function_call__10,
	wasmer_trampoline_function_call__11,
	wasmer_trampoline_function_call__12,
};

// Dynamic trampolines are per-function and are used for each function where
// the type signature is not known statically. In this case, this corresponds to
// the imported functions.
void wasmer_trampoline_dynamic_function__0(void*, void*, void*);
void wasmer_trampoline_dynamic_function__1(void*, void*, void*);
void wasmer_trampoline_dynamic_function__2(void*, void*, void*);
void wasmer_trampoline_dynamic_function__3(void*, void*, void*);
void wasmer_trampoline_dynamic_function__4(void*, void*, void*);
void wasmer_trampoline_dynamic_function__5(void*, void*, void*);
void wasmer_trampoline_dynamic_function__6(void*, void*, void*);
void wasmer_trampoline_dynamic_function__7(void*, void*, void*);
void wasmer_trampoline_dynamic_function__8(void*, void*, void*);
void wasmer_trampoline_dynamic_function__9(void*, void*, void*);
void wasmer_trampoline_dynamic_function__10(void*, void*, void*);
void wasmer_trampoline_dynamic_function__11(void*, void*, void*);
typedef void (*dyn_func_trampoline_t)(void*, void*, void*);
const dyn_func_trampoline_t dynamic_function_trampoline_pointers[] = {
	wasmer_trampoline_dynamic_function__0,
	wasmer_trampoline_dynamic_function__1,
	wasmer_trampoline_dynamic_function__2,
	wasmer_trampoline_dynamic_function__3,
	wasmer_trampoline_dynamic_function__4,
	wasmer_trampoline_dynamic_function__5,
	wasmer_trampoline_dynamic_function__6,
	wasmer_trampoline_dynamic_function__7,
	wasmer_trampoline_dynamic_function__8,
	wasmer_trampoline_dynamic_function__9,
	wasmer_trampoline_dynamic_function__10,
	wasmer_trampoline_dynamic_function__11,
};

wasm_byte_vec_t generate_serialized_data() {
        // We need to pass all the bytes as one big buffer so we have to do all this logic to memcpy
        // the various pieces together from the generated header file.
        //
        // We should provide a `deseralize_vectored` function to avoid requiring this extra work.

        char* byte_ptr = (char*)&WASMER_METADATA[0];

        size_t num_function_pointers
                = sizeof(function_pointers) / sizeof(void*);
        size_t num_function_trampolines
                = sizeof(function_trampolines) / sizeof(void*);
        size_t num_dynamic_function_trampoline_pointers
                = sizeof(dynamic_function_trampoline_pointers) / sizeof(void*);


        size_t buffer_size = module_bytes_len
                + sizeof(size_t) + sizeof(function_pointers)
                + sizeof(size_t) + sizeof(function_trampolines)
                + sizeof(size_t) + sizeof(dynamic_function_trampoline_pointers);

        char* memory_buffer = (char*) malloc(buffer_size);
        size_t current_offset = 0;

        memcpy(memory_buffer + current_offset, byte_ptr, module_bytes_len);
        current_offset += module_bytes_len;

        memcpy(memory_buffer + current_offset, (void*)&num_function_pointers, sizeof(size_t));
        current_offset += sizeof(size_t);

        memcpy(memory_buffer + current_offset, (void*)&function_pointers[0], sizeof(function_pointers));
        current_offset += sizeof(function_pointers);

        memcpy(memory_buffer + current_offset, (void*)&num_function_trampolines, sizeof(size_t));
        current_offset += sizeof(size_t);

        memcpy(memory_buffer + current_offset, (void*)&function_trampolines[0], sizeof(function_trampolines));
        current_offset += sizeof(function_trampolines);

        memcpy(memory_buffer + current_offset, (void*)&num_dynamic_function_trampoline_pointers, sizeof(size_t));
        current_offset += sizeof(size_t);

        memcpy(memory_buffer + current_offset, (void*)&dynamic_function_trampoline_pointers[0], sizeof(dynamic_function_trampoline_pointers));
        current_offset += sizeof(dynamic_function_trampoline_pointers);

        wasm_byte_vec_t module_byte_vec = {
                .size = buffer_size,
                .data = memory_buffer,
        };
        return module_byte_vec;
}

wasm_module_t* wasmer_object_file_engine_new(wasm_store_t* store, const char* wasm_name) {
        // wasm_name intentionally unused for now: will be used in the future.
        wasm_byte_vec_t module_byte_vec = generate_serialized_data();
        wasm_module_t* module = wasm_module_deserialize(store, &module_byte_vec);
        free(module_byte_vec.data);

        return module;
}


#ifdef __cplusplus
}
#endif
